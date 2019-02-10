// ConsoleApplication1.cpp: ������� ���� �������.
// ��������� Rest Listeners ��� ������ �������� �������


#include "stdafx.h"
#include "Listener.h"

using namespace System;



int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"����������, ���!");
	
	//��������� ���� ������ � ���, ��� ����������� ������ 
	// todo: rewrite to load database by name in query id caches is empty
	DataBaseAccess::getInstance()->init();
	
	//��������� rest listener �� ������������� ������� �� �������� ������������ ����
	WayController^ listenerWay = gcnew WayController();
	listenerWay->process();

	//��������� rest listener �� ������������� ������� �� �������� ������ �����
	MapController^ listenerMap = gcnew MapController();
	listenerMap->process();

    return 0;
}
