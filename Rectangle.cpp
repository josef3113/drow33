#pragma once
	#include "stdafx.h"
#include "Rectangle.h"



MYRectangle::MYRectangle(CPoint A,CPoint C,int R,int G,int B )
{
	this->R=R;
	this->G=G;
	this->B=B;
	this->A=A;                          // A from inheritance of Polygon
	this->C=C;                          // C from inheritance of Polygon
	
	

}

MYRectangle::MYRectangle(const MYRectangle& other)
{
  (*this)=other;    //because no have pointers it ok to use in operator =

}

MYRectangle::~MYRectangle(void)
{
}


//----setres

void MYRectangle::setA(const CPoint & p)
{
	this->A=p;
	
}

void MYRectangle::setC(const CPoint & p)    
{
	this->C=p;
	
}




//-------- its considered attributes 

int MYRectangle::getLenght()const
{
	return abs( C.x-A.x );
}


int MYRectangle::getWidth()const
{
	return abs( C.y-A.y );
}

//-----operators

void MYRectangle::operator=(const MYRectangle& other)
{
	this->A=other.A;
	this->C=other.C;
	
	
}


//-----function of MYRectangle

double MYRectangle:: getArea()const
{
	return ( ( this->getLenght() ) *  ( this->getWidth() ) );
}

double MYRectangle::getPerimeter()const
{
	return 2*( ( this->getLenght() )  +  ( this->getWidth() ) );
}

void MYRectangle::Draw(CDC *dc)
{
	dc->Rectangle(this->A.x,this->A.y,this->C.x,this->C.y) ;
}