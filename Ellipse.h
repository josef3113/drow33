#ifndef CIRCLE_H
#define CIRCLE_H

#include "stdafx.h"
#include "Shape.h"



# define  PHI 3.1415               //to calculate area and perimeter of circle


class MYEllipse :public Shape
{
private:
	
	CPoint A;
	CPoint C ;
	//int R,G,B;

public:
	

	MYEllipse(CPoint=(0,0) , CPoint=(0,0),int R=0,int G=0,int B=0 );  //difult constractor
	//MYEllipse(const MYEllipse&);               //copy constractor
	~MYEllipse();

	//---setres
	//Ellipse& setCenter(const Point&);
	//Ellipse& setRadius(const int &);

	//---geters

	////Point getCenter()const;
	///int getRadius()const;

	//-------operators
	//MYEllipse& operator =(const MYEllipse&);

	void Draw(CDC *dc);

	//----function of Ellipse
	double getArea()const;
	double getPerimeter()const;

};

#endif