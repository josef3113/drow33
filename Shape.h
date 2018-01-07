#ifndef SHAPE_H
#define SHAPE_H
#include "stdafx.h"

#include <iostream>
using namespace std;

class Shape
{
public:
	 int R,G,B;
	 CPoint A;
	 CPoint C;
	Shape(){}
	
	virtual bool isinshap(int x,int y)=0;
	virtual void select()=0;
	virtual void moved()=0;
    virtual void Draw(CDC *dc)=0;

	virtual ~Shape(){}
};

#endif