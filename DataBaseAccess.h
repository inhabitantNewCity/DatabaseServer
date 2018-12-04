#pragma once
#include "Map.h"
#include "Stubs.h"

using namespace System::Windows::Shapes;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class DataBaseAccess
{
private:
	List<Line^>^ map;
	List<Line^>^ way;

public:
	DataBaseAccess() {
		map = gcnew List<Line^>();
		way = gcnew List<Line^>();
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