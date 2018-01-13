#include "stdafx.h"
#include "Line.h"
#include "Shape.h"


IMPLEMENT_SERIAL (MYLine, CObject, 1)
   

MYLine::MYLine(int Ax ,int Ay, int Cx,int Cy,int R,int G,int B,int sizeLpen )
{
	this->Ax=Ax;
	this->Ay=Ay;

	this->Cx=Cx;
	this->Cy=Cy;

	this->R=R;
	this->G=G;
	this->B=B;

	this->sizeLpen=sizeLpen;
	

}


MYLine::~MYLine(void)
{
}



//----function 


void MYLine::Draw(CDC *dc)
{
	dc->MoveTo(Ax,Ay);
	dc->LineTo(Cx,Cy);
}



void MYLine:: Serialize (CArchive& ar)
	{
		MShape::Serialize (ar);
		if (ar.IsStoring ())
		{
			ar << sizeLpen;
		}
		else
		{
			ar >> sizeLpen;
		}
	}

