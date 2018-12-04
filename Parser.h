#pragma once
#include "Map.h"

using namespace System;

ref class Parser
{
private:
	array<unsigned char>^ parseString(String^ str) {
		array<unsigned char>^ bytes;
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
		String^ result = "";
		return parseString(result);
	}

	array<unsigned char>^ parseWay(Way^ way) {
		String^ result = "";
		return parseString(result);
	}
	
};

