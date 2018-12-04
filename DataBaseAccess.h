#pragma once
#include "Map.h"
#include "Stubs.h"

using namespace System::Collections::Generic;

ref class DataBaseAccess
{
private:
	List<PMK::Line^>^ map;
	List<PMK::Line^>^ way;

public:
	DataBaseAccess() {
		map = gcnew List<PMK::Line^>();
		way = gcnew List<PMK::Line^>();
		databaseGenerate(map, way);
	};
	~DataBaseAccess() {};
	Map^ getMap() {
		return gcnew Map(map);
	}

	Way^ getWay() {
		return gcnew Way(way);
	}
};