#include "stdafx.h"

#include "Ellipse.h"
#include "Rectangle.h"
#include "Shape.h"
#include <MMSystem.h>

//IMPLEMENT_SERIAL (MYEllipse, CObject, 1)
//IMPLEMENT_SERIAL (MYRectangle, CObject, 1)
//IMPLEMENT_SERIAL (Shape, CObject, 1)




MYEllipse::MYEllipse(int Ax ,int Ay, int Cx,int Cy,int R,int G,int B )
{
	this->Ax=Ax;
	this->Ay=Ay;

	this->Cx=Cx;
	this->Cy=Cy;

	this->R=R;
	this->G=G;
	this->B=B;
	

}


MYEllipse::~MYEllipse(void)
{
}



//----function of MYEllipse

bool MYEllipse::isinshap(int x,int y)
{
	{
		if( (x > this->Ax) && (x < this->Cx) && (y > this->Ay) && (y < this->Cy) )
			return true;
		else
			return false;
	}
}

void MYEllipse::Draw(CDC *dc)
{
	dc->Ellipse(Ax,Ay,Cx,Cy);
}

void MYEllipse::select()
{
  PlaySound(TEXT("ellipse_selected.wav"),NULL,SND_ASYNC|SND_FILENAME);
}

void MYEllipse::moved()
{
	 PlaySound(TEXT("Moved_Ellipse.wav"),NULL,SND_ASYNC|SND_FILENAME);
}

