#ifndef POLYGON_H
#define POLYGON_H
#include "stdafx.h"
#include "Shape.h"



class MPolygon :public MShape
{

 DECLARE_SERIAL (MPolygon)
public:

	MPolygon(){};
	~MPolygon(){};


};
#endif
