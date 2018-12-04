#include "way_load.h"
#pragma once

using namespace System::Collections::Generic;
using namespace System::Windows::Shapes;


int databaseGenerate(List<Line^>^ map, List<Line^>^ way) {
	
	char* basename = new char[11];
	basename[0] = 'C';
	basename[1] = 'O';
	basename[2] = 'R';
	basename[3] = 'P';
	basename[4] = '1';
	basename[5] = 'F';
	basename[6] = 'L';
	basename[7] = 'O';
	basename[8] = 'O';
	basename[9] = 'R';
	basename[10] = '2';
	basename[11] = '.';
	basename[12] = 'D';
	basename[13] = 'P';
	basename[14] = 'F';

	int *countMap, *countWay;
	GBaseWay* mapCor = GetMap(countMap, basename);
	Coord* wayCor = GetWay(mapCor[0].way[0], mapCor[*countMap - 1].way[0], countWay, basename);


	for (int i = 0; i < *countMap; i++) {
		for (int j = 0; j < mapCor[i].size - 1; j++) {
			Line^ line = gcnew Line();
			line->X1 = mapCor[i].way[j].x_;
			line->Y1 = mapCor[i].way[j].y_;
			line->X2 = mapCor[i + 1].way[j].x_;
			line->Y2 = mapCor[i + 1].way[j].y_;
			map->Add(line);
		}
	}

	for (int i = 0; i < *countWay - 1; i++) {
		Line^ line = gcnew Line();
		line->X1 = wayCor[i].x_;
		line->Y1 = wayCor[i].y_;
		line->X2 = wayCor[i + 1].x_;
		line->Y2 = wayCor[i + 1].y_;
		way->Add(line);
	}

	return 0;

}