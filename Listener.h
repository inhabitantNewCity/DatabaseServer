#pragma once
#include "DataBaseAccess.h"
#include "Parser.h"

using namespace System;
using namespace System::Text;
using namespace System::Net::Sockets;
using namespace System::Net;
using namespace System::Threading;
using namespace System::IO;

ref class MapController {
private:
	static HttpListener^ listener;
	static Parser^ parser;
	static DataBaseAccess^ dataBaseAcces;

	Thread^ listenThread1;

public: MapController() {
	listener = gcnew HttpListener();
	listener->Prefixes->Add("http://localhost:8080/map/");
	listener->AuthenticationSchemes = AuthenticationSchemes::Anonymous;

	listener->Start();

	listenThread1 = gcnew Thread(gcnew ParameterizedThreadStart(&MapController::startlistener));
	parser = gcnew Parser();
	dataBaseAcces = DataBaseAccess::getInstance();

	Console::WriteLine(L"Map controller is configurated");
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
		IAsyncResult^ result = listener->BeginGetContext(gcnew AsyncCallback(&MapController::ListenerCallback), listener);
		result->AsyncWaitHandle->WaitOne();
	}

public: static void ListenerCallback(IAsyncResult^ result)
	{
		HttpListenerContext^ context = listener->EndGetContext(result);
		Thread::Sleep(1000);
		String^ data_text = (gcnew StreamReader(context->Request->InputStream, context->Request->ContentEncoding))->ReadToEnd();


		array<unsigned char>^ map = parser->parseMap(dataBaseAcces->getMap());
		
		Console::WriteLine(map);
		
		context->Response->OutputStream->WriteAsync(map, 0, map->Length);
		
		context->Response->StatusCode = 200;
		context->Response->StatusDescription = "OK";
		
		context->Response->Close();
	}

public:

	void process() {
		listenThread1->Start();
	}

	~MapController() {};
};


ref class WayController {
private:
	static HttpListener^ listener;
	static Parser^ parser;
	static DataBaseAccess^ dataBaseAcces;

	Thread^ listenThread1;

public: WayController() {
	listener = gcnew HttpListener();
	listener->Prefixes->Add("http://localhost:8080/way/");
	listener->AuthenticationSchemes = AuthenticationSchemes::Anonymous;

	listener->Start();

	listenThread1 = gcnew Thread(gcnew ParameterizedThreadStart(&WayController::startlistener));
	parser = gcnew Parser();
	dataBaseAcces = DataBaseAccess::getInstance();

	Console::WriteLine(L"Way controller is configurated");
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
	IAsyncResult^ result = listener->BeginGetContext(gcnew AsyncCallback(&WayController::ListenerCallback), listener);
	result->AsyncWaitHandle->WaitOne();
}

public: static void ListenerCallback(IAsyncResult^ result)
{
	HttpListenerContext^ context = listener->EndGetContext(result);
	Thread::Sleep(1000);
	String^ data_text = (gcnew StreamReader(context->Request->InputStream, context->Request->ContentEncoding))->ReadToEnd();

	Console::WriteLine(data_text);

	array<unsigned char>^ way = parser->parseWay(dataBaseAcces->getWay());
	Console::WriteLine(way);
	context->Response->OutputStream->WriteAsync(way, 0, way->Length);

	context->Response->StatusCode = 200;
	context->Response->StatusDescription = "OK";

	context->Response->Close();
}

public:

	void process() {
		listenThread1->Start();
	}

	~WayController() {};
};