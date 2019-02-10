// ConsoleApplication1.cpp: главный файл проекта.
// Запускает Rest Listeners для работы ожидания запроса


#include "stdafx.h"
#include "Listener.h"

using namespace System;



int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"«дравствуй, мир!");
	
	//загружает базу данных в кеш, для оперативной работы 
	// todo: rewrite to load database by name in query id caches is empty
	DataBaseAccess::getInstance()->init();
	
	//запускает rest listener на прослушивание запроса на загрузку оптимального пути
	WayController^ listenerWay = gcnew WayController();
	listenerWay->process();

	//запускает rest listener на прослушивание запроса на загрузку полной карты
	MapController^ listenerMap = gcnew MapController();
	listenerMap->process();

    return 0;
}
