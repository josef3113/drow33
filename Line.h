#ifndef LINE_H
#define LINE_H

#include "stdafx.h"
#include "Shape.h"



class MYLine :public Shape
{


public:
	int sizeLpen;
	

	MYLine(CPoint=(0,0) , CPoint=(0,0),int R=0,int G=0,int B=0 ,int =0 );  //difult constractor
	~MYLine();

	void Draw(CDC *dc);
	bool isinshap(int x,int y){return false;}
	void select(){};
	void moved(){};
	


};

#endif