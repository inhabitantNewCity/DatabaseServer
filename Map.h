#pragma once
#include "Line.h"
using namespace System::Collections::Generic;

// содержит полную структуру путей движдений
// может быть расширена в рамках решения
ref class Map {
	
private:
	List<PMK::Line^>^ lines;
public:
	
	Map(List<PMK::Line^>^ intervals) {
		this->lines = intervals;
	}

	List<PMK::Line^>^ getLines() {
		return lines;
	}

};

// содержит полную структуру оптимального пити движдений
// может быть расширена в рамках решения
ref class Way{
private:
	PMK::Point^ startPoint;
	PMK::Point^ endPoint;
	List<PMK::Line^>^ intervals;
public: 
	
	Way(List<PMK::Line^>^ intervals){
		this->intervals = intervals;
	}

	PMK::Point^ getStartPoint() {
		return startPoint;
	}

	PMK::Point^ getEndPoint() {
		return endPoint;
	}

	List<PMK::Line^>^ getList() {
		return intervals;
	}

	void setStartPoint(PMK::Point^ startPoint) {
		this->startPoint = startPoint;
	}

	void setEndPoint(PMK::Point^ endPoint) {
		this->endPoint = endPoint;
	}
};