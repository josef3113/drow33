#ifndef POLYGON_H
#define POLYGON_H
#include "stdafx.h"
#include "Shape.h"
//#include "Pointh.h"


class Polygon :public Shape
{
protected :
	CPoint A;
	CPoint C;

public:

	Polygon(){};
	~Polygon(){};    //it's inheretance from shape so it is virtual too

	//double getEdge(const CPoint &A,const CPoint &B)const {return A.getDistance(B);}
	CPoint getA()const{return A;}
	CPoint getC()const{return C;}




};
#endif
