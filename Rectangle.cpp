#pragma once
#include "stdafx.h"
#include "Rectangle.h"
#include <MMSystem.h>



MYRectangle::MYRectangle(CPoint A,CPoint C,int R,int G,int B )
{
	this->R=R;
	this->G=G;
	this->B=B;
	this->A=A;                          // A from inheritance of Polygon
	this->C=C;                          // C from inheritance of Polygon
	
	

}


MYRectangle::~MYRectangle(void)
{
}



void MYRectangle::Draw(CDC *dc)
{
	dc->Rectangle(this->A.x,this->A.y,this->C.x,this->C.y) ;
}

bool MYRectangle::isinshap(int x,int y)
{
	{
		if( (x > this->A.x) && (x < this->C.x) && (y > this->A.y) && (y < this->C.y) )
			return true;
		else
			return false;
	}
}

void MYRectangle::select()
{
	 PlaySound(TEXT("Rectengle_Selected.wav"),NULL,SND_ASYNC|SND_FILENAME);
}

void MYRectangle::moved()
{
	 PlaySound(TEXT("Moved_Rectangle.wav"),NULL,SND_ASYNC|SND_FILENAME);
}