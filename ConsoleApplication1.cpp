// ConsoleApplication1.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Listener.h"

using namespace System;



int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"����������, ���!");
	DataBaseAccess::getInstance()->init();
	WayController^ listenerWay = gcnew WayController();
	listenerWay->process();

	MapController^ listenerMap = gcnew MapController();
	listenerMap->process();

    return 0;
}
