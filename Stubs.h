#include "way_load.h"
#include "Line.h"
#pragma once

using namespace System::Collections::Generic;
using namespace System::IO;


void updateWay(PMK::Point^ start, PMK::Point^ finish, List<PMK::Line^>^ way) {
	way->Clear();

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

	int countWay = 0;
	Coord start_c, finish_c;

	start_c.x_ = start->x;
	start_c.y_ = start->y;
	finish_c.x_ = finish->x;
	finish_c.y_ = finish->y;

	Coord* wayCor = GetWay(start_c, finish_c, &countWay, basename);
	way->Clear();

	for (int i = 0; i < countWay - 1; i++) {
		PMK::Line^ line = gcnew PMK::Line();
		line->setX1((float)(wayCor[i].x_));
		line->setY1((float)(wayCor[i].y_));
		line->setX2((float)(wayCor[i + 1].x_));
		line->setY2((float)(wayCor[i + 1].y_));
		way->Add(line);
	}
}


int databaseGenerate(List<PMK::Line^>^ map, List<PMK::Line^>^ way) {

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

	int countMap;
	int countWay;
	GBaseWay* mapCor = GetMap(&countMap, basename);
	Coord* wayCor = GetWay(mapCor[0].way[3], mapCor[0].way[mapCor[0].size - 1], &countWay, basename);

	StreamWriter^ sw = File::CreateText("../logs/LogLine.txt");
	sw->WriteLine("Replication data with parameter: count ways:" + countMap);

	for (int numberLine = 0, i = 0; i < countMap; i++) {
		sw->WriteLine("Replication " + (i + 1) + " way data with parameter: count vertex:" + mapCor[i].size);
		for (int j = 0; j < mapCor[i].size - 1; j++, numberLine++) {
			PMK::Line^ line = gcnew PMK::Line();
			line->setX1((float)(mapCor[i].way[j].x_));
			line->setY1((float)(mapCor[i].way[j].y_));
			line->setX2((float)(mapCor[i].way[j + 1].x_));
			line->setY2((float)(mapCor[i].way[j + 1].y_));
			sw->WriteLine("Line: {(" + line->getX1() + ", " + line->getY1() + "), (" + line->getX2() + ", " + line->getY2() + ")} number = " + numberLine);
			map->Add(line);
		}
	}
	sw->WriteLine("Opt way");
	for (int i = countWay - 1; i > 0; i--) {
		PMK::Line^ line = gcnew PMK::Line();
		line->setX1((float)(wayCor[i].x_));
		line->setY1((float)(wayCor[i].y_));
		line->setX2((float)(wayCor[i - 1].x_));
		line->setY2((float)(wayCor[i - 1].y_));
		way->Add(line);
		sw->WriteLine("Line: {(" + line->getX1() + ", " + line->getY1() + "), (" + line->getX2() + ", " + line->getY2() + ")}");
	}

	delete[] mapCor;
	sw->Flush();
	return 0;

}
