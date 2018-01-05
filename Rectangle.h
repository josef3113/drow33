#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "stdafx.h"
#include "Polygon.h"

class MYRectangle :public Polygon
{
		

public:


	MYRectangle( CPoint=(0,0) , CPoint=(0,0),int R=0,int G=0,int B=0 ); //defult constractor
	MYRectangle(const MYRectangle&);            //copy constractor
	~MYRectangle();


	//----setres

	void setA(const CPoint&);
    void setC(const CPoint&);

	//-----getrs  inheritance from polygon


	//-----its considered attribute

	int getLenght()const;
	int getWidth()const;

	//------operators
	void operator=(const MYRectangle &);

	//----function of Rectangle

	void Draw(CDC *dc);
     
	double getArea()const;
	double getPerimeter()const;

};

#endif