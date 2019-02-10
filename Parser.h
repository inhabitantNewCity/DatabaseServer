#pragma once
#include "Map.h"

using namespace System;

// сервис для формирования json строки по полученным database сущностям
ref class Parser
{
private:
	array<unsigned char>^ parseString(String^ str) {
		array<unsigned char>^ bytes = gcnew array<unsigned char>(str->Length);
		array<wchar_t>^ chars = str->ToCharArray();
		for (int i = 0; i < str->Length; i++) {
			bytes[i] = chars[i];
		}
		return bytes;
	}
	
	String^ parseList(List<PMK::Line^>^ list) {
		StringBuilder^ sb = gcnew StringBuilder("[");
		for (int i = 0; i < list->Count - 1; i++) {
			sb->Append(list[i]->ToString());
			sb->Append(",\n");
		}
		sb->Append(list[list->Count - 1]->ToString());
		sb->Append("]");
		return sb->ToString();
	}
public:
	Parser() {};
	~Parser() {};

	array<unsigned char>^ parseMap(Map^ map) {
		List<PMK::Line^>^ list = map->getLines();
		return parseString(parseList(list));
	}

	array<unsigned char>^ parseWay(Way^ way) {
		List<PMK::Line^>^ list = way->getList();
		return parseString(parseList(list));
	}
	
};

