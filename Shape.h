#pragma once

/*
#ifndef SHAPE_H
#define SHAPE_H
//#include "stdafx.h"
#include "afx.h"
#include "afxdialogex.h"
  

#include <iostream>
using namespace std;
 */ 

class MShape: public CObject 
{
	
	DECLARE_SERIAL (MShape)
public:
	
	 int R,G,B;
	// CPoint A;
	// CPoint C;

	 int Ax,Ay,Cx,Cy;
public:
	MShape();
	
	virtual bool isinshap(int x,int y){return false;}
	virtual void select(){}
	virtual void moved(){}
	virtual void Draw(CDC *dc){}
	virtual ~MShape(){}

	void Serialize (CArchive& ar)
	{
		CObject::Serialize (ar);
		if (ar.IsStoring ())
		{
			ar<<R;
			ar<<G;
			ar<<B;

			ar << Ax;
			ar<<Ay ;
			ar << Cx;
			ar<< Cy;
			//!!7 //ar << KIND;
		}
		else // Loading, not storing
		{
			ar>> R;
			ar>> G;
			ar>> B;
			ar >> Ax;
			ar>> Ay;
			ar >> Cx;
			ar>>Cy;
			
			//!!7 //ar >> KIND;
		}
	}
	
};

//#endif