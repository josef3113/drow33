#include "stdafx.h"
#include "Ellipse.h"
#include "Shape.h"
#include <MMSystem.h>



MYEllipse::MYEllipse(CPoint A , CPoint C,int R,int G,int B )
{
	this->A=A;
	this->C=C;

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
		if( (x > this->A.x) && (x < this->C.x) && (y > this->A.y) && (y < this->C.y) )
			return true;
		else
			return false;
	}
}

void MYEllipse::Draw(CDC *dc)
{
	dc->Ellipse(A.x,A.y,C.x,C.y);
}

void MYEllipse::select()
{
  PlaySound(TEXT("ellipse_selected.wav"),NULL,SND_ASYNC|SND_FILENAME);
}

void MYEllipse::moved()
{
	 PlaySound(TEXT("Moved_Ellipse.wav"),NULL,SND_ASYNC|SND_FILENAME);
}

