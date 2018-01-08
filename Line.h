#ifndef LINE_H
#define LINE_H

#include "stdafx.h"
#include "Shape.h"



class MYLine :public Shape
{


public:
	int sizeLpen;
	

	MYLine(int Ax , int Ay,int Cx,int Cy,int R,int G,int B,int sizeLpen );  //difult constractor
	~MYLine();
	MYLine(){}

	void Draw(CDC *dc);
	bool isinshap(int x,int y){return false;}
	void select(){};
	void moved(){};
	


};

#endif