#pragma once
#include "DataBaseAccess.h"
#include "Parser.h"

using namespace System;
using namespace System::Text;
using namespace System::Net::Sockets;
using namespace System::Net;
using namespace System::Threading;
using namespace System::IO;

ref class DataAccessListener {
private:
	static HttpListener^ listener;
	static Parser^ parser;
	static DataBaseAccess^ dataBaseAcces;

	Thread^ listenThread1;

public: DataAccessListener() {
	listener = gcnew HttpListener();
	listener->Prefixes->Add("http://localhost:8080/map/");
	listener->AuthenticationSchemes = AuthenticationSchemes::Anonymous;

	listener->Start();

	listenThread1 = gcnew Thread(gcnew ParameterizedThreadStart(&DataAccessListener::startlistener));
	parser = gcnew Parser();
	dataBaseAcces = gcnew DataBaseAccess();

	Console::WriteLine(L"Listener is configurated");
}

public: static void startlistener(Object^ s)
	{
		while (true)
		{
			ProcessRequest();
		}
	}

public: static void ProcessRequest()
	{
		IAsyncResult^ result = listener->BeginGetContext(gcnew AsyncCallback(&DataAccessListener::ListenerCallback), listener);
		result->AsyncWaitHandle->WaitOne();
	}

public: static void ListenerCallback(IAsyncResult^ result)
	{
		HttpListenerContext^ context = listener->EndGetContext(result);
		Thread::Sleep(1000);
		String^ data_text = (gcnew StreamReader(context->Request->InputStream, context->Request->ContentEncoding))->ReadToEnd();

		Console::WriteLine(data_text);

		array<unsigned char>^ map = parser->parseMap(dataBaseAcces->getMap());
		
		context->Response->OutputStream->WriteAsync(map, 0, map->Length);
		
		context->Response->StatusCode = 200;
		context->Response->StatusDescription = "OK";
		
		context->Response->Close();
	}

public:

	void process() {
		listenThread1->Start();
	}

	~DataAccessListener() {};
};