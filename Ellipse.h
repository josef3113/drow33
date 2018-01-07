#ifndef CIRCLE_H
#define CIRCLE_H

#include "stdafx.h"
#include "Shape.h"



class MYEllipse :public Shape
{


public:
	

	MYEllipse(CPoint=(0,0) , CPoint=(0,0),int R=0,int G=0,int B=0 );  //difult constractor
	~MYEllipse();

	void Draw(CDC *dc);
	bool isinshap(int x,int y);
	 void select();
	 void moved();


};

#endif