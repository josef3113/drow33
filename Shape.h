#ifndef SHAPE_H
#define SHAPE_H
#include "stdafx.h"

#include <iostream>
//#include "square.h"
using namespace std;

class Shape
{
public:
	 int R,G,B;
	Shape(){}
	
	virtual double getArea()const=0;
	virtual double getPerimeter()const=0;

	virtual void Draw(CDC *dc)=0;

	virtual ~Shape(){}
};

#endif