// ConsoleApplication1.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Listener.h"

using namespace System;



int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"����������, ���!");
	
	DataAccessListener^ listener = gcnew DataAccessListener();
	listener->process();

    return 0;
}
