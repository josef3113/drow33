#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "stdafx.h"
#include "Polygon.h"

class MYRectangle :public MPolygon
{
	
	DECLARE_SERIAL (MYRectangle)

public:


	MYRectangle(int Ax , int Ay,int Cx,int Cy,int R=0,int G=0,int B=0 ); 
	MYRectangle(){}
	~MYRectangle();

	
	//----function of Rectangle

	void Draw(CDC *dc);
	void select();
	void moved();
	
     

};


///////////------square


class MYSquare :public MYRectangle
{
	
	DECLARE_SERIAL (MYSquare)

public:


	MYSquare(int Ax , int Ay,int Cx,int Cy,int R,int G,int B );
	~MYSquare(){}
	MYSquare(){}

	
	//----function of Rectangle

	void select();
	void moved();
	
     

};



#endif