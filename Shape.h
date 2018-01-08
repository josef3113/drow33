#ifndef SHAPE_H
#define SHAPE_H
#include "stdafx.h"
#include "afx.h"
#include "afxdialogex.h"


#include <iostream>
using namespace std;

class Shape	   //: public CObject 
{
	//DECLARE_SERIAL (Shape)
	
public:
	
	 int R,G,B;
	// CPoint A;
	// CPoint C;

	 int Ax,Ay,Cx,Cy;

	 Shape(){}
	
	virtual bool isinshap(int x,int y){return false;}
	virtual void select(){}
	virtual void moved(){}
	virtual void Draw(CDC *dc){}

	//void Serialize (CArchive& ar)
	//{
	//	CObject::Serialize (ar);
	//	if (ar.IsStoring ())
	//	{
	//		ar<<R;
	//		ar<<G;
	//		ar<<B;

	//		ar << Ax;
	//		ar << Cx;
	//		//!!7 //ar << KIND;
	//	}
	//	else // Loading, not storing
	//	{
	//		ar >> Ax;
	//		ar >> Cx;
	//		
	//		//!!7 //ar >> KIND;
	//	}
	//}

	virtual ~Shape(){}
};

#endif