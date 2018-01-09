#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "stdafx.h"
#include "Polygon.h"

class MYRectangle :public MPolygon
{
	
	DECLARE_SERIAL (MYRectangle)

public:


	MYRectangle(int Ax , int Ay,int Cx,int Cy,int R=0,int G=0,int B=0 ); //defult constractor
	~MYRectangle();
	MYRectangle(){}

	
	//----function of Rectangle

	void Draw(CDC *dc);
	bool isinshap(int x,int y) ;
	void select();
	void moved();
	
     

};


class MYSquare :public MYRectangle
{
	
	DECLARE_SERIAL (MYSquare)

public:


	MYSquare(int Ax , int Ay,int Cx,int Cy,int R,int G,int B ); //defult constractor
	~MYSquare(){}
	MYSquare(){}

	
	//----function of Rectangle

	//void Draw(CDC *dc);
	//bool isinshap(int x,int y) ;
	//void select();
	//void moved();
	
     

};



#endif