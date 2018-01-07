#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "stdafx.h"
#include "Polygon.h"

class MYRectangle :public Polygon
{
		

public:


	MYRectangle( CPoint=(0,0) , CPoint=(0,0),int R=0,int G=0,int B=0 ); //defult constractor
	~MYRectangle();

	
	//----function of Rectangle

	void Draw(CDC *dc);
	bool isinshap(int x,int y) ;
	void select();
	void moved();
	
     

};

#endif