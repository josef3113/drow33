#include "stdafx.h"
#include "Line.h"
#include "Shape.h"




MYLine::MYLine(CPoint A , CPoint C,int R,int G,int B )
{
	this->A=A;
	this->C=C;

	this->R=R;
	this->G=G;
	this->B=B;
	

}


MYLine::~MYLine(void)
{
}



//----function of MYEllipse


void MYLine::Draw(CDC *dc)
{
	dc->MoveTo(A);
	dc->LineTo(C);
}

