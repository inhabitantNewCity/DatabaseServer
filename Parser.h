#pragma once
#include "Map.h"

using namespace System;

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
public:
	Parser() {};
	~Parser() {};

	array<unsigned char>^ parseMap(Map^ map) {
		StringBuilder^ sb = gcnew StringBuilder("[");
		List<PMK::Line^>^ list = map->getLines();
		for (int i = 0; i < list->Count - 1; i++) {
			sb->Append(list[i]->ToString());
			sb->Append(",\n");
		}
		sb->Append(list[list->Count - 1]->ToString());
		sb->Append("]");
		return parseString(sb->ToString());
	}

	array<unsigned char>^ parseWay(Way^ way) {
		String^ result = "parse way";
		return parseString(result);
	}
	
};

