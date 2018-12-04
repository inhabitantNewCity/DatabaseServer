// ConsoleApplication1.cpp: главный файл проекта.

#include "stdafx.h"
#include "Listener.h"

using namespace System;



int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Здравствуй, мир!");
	
	DataAccessListener^ listener = gcnew DataAccessListener();
	listener->process();

    return 0;
}
