#include "stdafx.h"
#include "Ellipse.h"
#include "Shape.h"




MYEllipse::MYEllipse(CPoint A , CPoint C,int R,int G,int B )
{
	this->A=A;
	this->C=C;

	this->R=R;
	this->G=G;
	this->B=B;
	

}

//MYEllipse::MYEllipse(const MYEllipse & other)
//{
//	(*this)=other;  //because no have pointer its ok to use in operator =
//}

MYEllipse::~MYEllipse(void)
{
}

//-----setres

//MYEllipse& MYEllipse::setCenter(const Point & p)
//{
//	this->Center=p;
//	return (*this);
//}
//
//MYEllipse& MYEllipse::setRadius(const int & r)
//{
//	this->radius=r;
//	return (*this);
//}


//------grters 

//Point MYEllipse::getCenter()const
//{
//	return this->Center;
//}
//
//int MYEllipse::getRadius()const
//{
//	return this->radius;
//}
//
//--------operators

//MYEllipse& MYEllipse:: operator =(const MYEllipse & other)
//{
//	this->A=other.A;
//	this->C=other.C;
//
//	this->R=other.R;
//	this->G=other.G;
//	this->B=other.B;
//
//	return (*this);
//}

//----function of MYEllipse 

void MYEllipse::Draw(CDC *dc)
{
	dc->Ellipse(A.x,A.y,C.x,C.y);
}

double MYEllipse::getArea()const
{
	return PHI;
}

double MYEllipse::getPerimeter()const
{
	return 2*PHI;
}