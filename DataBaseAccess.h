#pragma once
#include "Map.h"
#include "Stubs.h"

using namespace System::Collections::Generic;

ref class DataBaseAccess
{
private:
	List<PMK::Line^>^ map;
	List<PMK::Line^>^ way;

	static DataBaseAccess^ instance;

public:
	DataBaseAccess() {
		map = gcnew List<PMK::Line^>();
		way = gcnew List<PMK::Line^>();
	};
	~DataBaseAccess() {};

	static DataBaseAccess^ getInstance() {
		if (instance == nullptr) {
			instance = gcnew DataBaseAccess();
		}
		return instance;
	}

	void init() {
		databaseGenerate(map, way);
	}

	Map^ getMap() {
		return gcnew Map(map);
	}

	Way^ getWay() {
		return gcnew Way(way);
	}
};