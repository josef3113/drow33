#pragma once
#include "stdafx.h"
#include "Rectangle.h"
#include <MMSystem.h>

IMPLEMENT_SERIAL (MYRectangle, CObject, 1)
IMPLEMENT_SERIAL (MYSquare, CObject, 1)



MYRectangle::MYRectangle(int Ax ,int Ay, int Cx,int Cy,int R,int G,int B )
{
	this->Ax=Ax;
	this->Ay=Ay;

	this->Cx=Cx;
	this->Cy=Cy;

	this->R=R;
	this->G=G;
	this->B=B;
	

}


MYRectangle::~MYRectangle(void)
{
}



void MYRectangle::Draw(CDC *dc)
{
	dc->Rectangle(this->Ax,this->Ay,this->Cx,this->Cy) ;
}

//bool MYRectangle::isinshap(int x,int y)
//{
//	{
//		if( (x > this->Ax) && (x < this->Cx) && (y > this->Ay) && (y < this->Cy) )
//			return true;
//		else
//			return false;
//	}
//}

void MYRectangle::select()
{
	 PlaySound(TEXT("Rectengle_Selected.wav"),NULL,SND_ASYNC|SND_FILENAME);
}

void MYRectangle::moved()
{
	 PlaySound(TEXT("Moved_Rectangle.wav"),NULL,SND_ASYNC|SND_FILENAME);
}




//////////////////////////////////////////

MYSquare::MYSquare(int Ax ,int Ay, int Cx,int Cy,int R,int G,int B )
{

	if(Ax-Cx ==Ay-Cy)
	{
		this->Ax=Ax;
		this->Ay=Ay;

		this->Cx=Cx;
		this->Cy=Cy;

		this->R=R;
		this->G=G;
		this->B=B;
	}
	else
	{
		this->Ax=0;
		this->Ay=0;

		this->Cx=0;
		this->Cy=0;

		this->R=0;
		this->G=0;
		this->B=0;

	}
	

}
void MYSquare::select()
{
	PlaySound(TEXT("square_selected.wav"),NULL,SND_ASYNC|SND_FILENAME);
}

void MYSquare::moved()
{
	PlaySound(TEXT("square_moved.wav"),NULL,SND_ASYNC|SND_FILENAME);
}