#include "stdafx.h"
#include "way_load.h"
#include "graph_dll.h"
#include "GeneralizationDataBaseLoadFuncs.h"
#include <conio.h>



//name_base="CORP1FLOOR2";
//#define BASE_NAME CORP1FLOOR2

struct {
	GBASE *dataBase;
} db;

struct GBaseCoord
{
	int x;
	int y;
};

using namespace std;
bool graph;
FILE *f;
Coord* GetWay(Coord coordStart, Coord coordEnd, int *n, char* namebase)
{
	int error_1;
	HINSTANCE hdll00;
	char* graphname;
	int len=strlen(namebase);
	//cout<<"len "<<len<<endl;
	graphname = new char[len+2];       
				 for(int j=0;j<len;j++)
				 {
				  graphname[j]=namebase[j]; 
				  graphname[len]='.';
				  graphname[len+1]='g';
				  graphname[len+2]=0;				
				 }  
	//cout<<"graphname "<<graphname<<endl;
	hdll00=BaseFun(&error_1,NULL);
	if (hdll00 == NULL)
	{
		//printf("Library not found");	
		return 0;
	}
	else 
		//printf("Library Graph_DLL_Project.dll  - OK\n");

//проверка на наличие такого графа!!
		f = fopen(graphname,"rb");
		if(!f)
		{
			cout<<"not_graph_file"<<endl;				
			return 0;	
		}
		else
		{
		_Load_Graph(graphname);	
		//  Close_Graph();	  
		int pointsCount=0;  
		Coord *path;
		pointsCount =_FindPath_Make(coordStart, coordEnd);
		*n = pointsCount;
		if (pointsCount==-1)
		 {  
			printf("pCount==-1\n");
		 }
		path=new Coord[pointsCount]; 
		_GetResultPath(path); 
		return path;
		// delete [] path;	
		}
}

Coord* readDataFromObject(GBASE_OBJECT object, int* countPoints) {
	Coord* result = new Coord[object.qMet];
	GBaseCoord* points = (GBaseCoord*)object.pMet;
	for (int i = 0; i < object.qMet; i++) {
		result[i].x_ = points[i].x;
		result[i].y_ = points[i].y;
	}
	return result;
}

GBaseWay* GetMap(int *n, char* namebase) {
	
	int err = 0;

	GBaseWay* result;
	int countPoints = 0;

	GBASE_QUERY Query;
	long countWays = 0;
	BASE_INT Code[10] = { 4, 30, 3, 1, 1 };
	GBASE_OBJECT Object;
	GeneralizationDataBaseLoadFuncs* loader = new GeneralizationDataBaseLoadFuncs();

	db.dataBase = loader->_BaseOpen(&err, "CORP1FLOOR2.DPF", "R", NULL, NULL);// return code = -4

	loader->_BaseInitQuery(&Query, 32767, 1);

	err = loader->_BaseObjectCount(db.dataBase, Code,
		OPEN_TREE, &countWays);
	
	err = loader->_BaseInitObject(&Object, NULL, 0, NULL, 1,
		NULL, 1, NULL, 0, NULL, 0,
		NULL, 0, NULL, 0);


	err = loader->_BaseReadObject(db.dataBase, &Query, NULL,
		OPEN_TREE, OBJ_FULL,
		&Object, Code, 0);

	result = new GBaseWay[countWays];
	
	if (err == 0) {
		result[0].way = readDataFromObject(Object, &countPoints);
		result[0].size = countPoints;
	}
	
	for (int i = 1; err == 0; i++) {
		loader->_BaseCloseObject(&Object);
		err = loader->_BaseReadObject(db.dataBase, &Query, NULL,
			READ_NEXT, OBJ_FULL,
			&Object, Code, 0);
		if (err == 0) {
			result[i].way = readDataFromObject(Object, &countPoints);
			result[i].size = countPoints;
		}
	}
		
	err = loader->_BaseClose(db.dataBase);
	
	delete[] loader;
	delete[] db.dataBase;

	*n = countWays;
	return result;

}