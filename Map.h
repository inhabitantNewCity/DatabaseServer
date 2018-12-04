#pragma once

using namespace System;
using namespace System::Windows::Shapes;
using namespace System::Drawing;
using namespace System::Collections::Generic;


ref class Map {
	
private:
	List<Line^>^ lines;
public:
	
	Map(List<Line^>^ intervals) {
		this->lines = intervals;
	}

	List<Line^>^ getLines() {
		return lines;
	}

};


ref class Way{
private:
	Point startPoint;
	Point endPoint;
	List<Line^>^ intervals;
public: 
	
	Way(List<Line^>^ intervals){
		this->intervals = intervals;
	}

	Point getStartPoint() {
		return startPoint;
	}

	Point getEndPoint() {
		return endPoint;
	}

	List<Line^>^ getList() {
		return intervals;
	}

	void setStartPoint(Point startPoint) {
		this->startPoint = startPoint;
	}

	void setEndPoint(Point endPoint) {
		this->endPoint = endPoint;
	}
};