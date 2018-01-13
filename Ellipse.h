#ifndef CIRCLE_H
#define CIRCLE_H

#include "stdafx.h"
#include "Shape.h"





class MYEllipse :public MShape
{

	  DECLARE_SERIAL (MYEllipse)
public:
	

	MYEllipse(int Ax , int Ay,int Cx,int Cy,int R=0,int G=0,int B=0 );  //difult constractor
	~MYEllipse();
	MYEllipse(){}


	void Draw(CDC *dc);
	//bool isinshap(int x,int y);
	 void select();
	 void moved();


};

#endif