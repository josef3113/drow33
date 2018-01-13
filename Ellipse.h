#ifndef CIRCLE_H
#define CIRCLE_H

#include "stdafx.h"
#include "Shape.h"





class MYEllipse :public MShape
{

	  DECLARE_SERIAL (MYEllipse)
public:
	

	MYEllipse(int Ax , int Ay,int Cx,int Cy,int R,int G,int B );  
	MYEllipse(){}
	~MYEllipse();


	void Draw(CDC *dc);
	 void select();
	 void moved();


};

#endif