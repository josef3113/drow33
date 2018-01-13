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
protected:
	
	 int R,G,B;
	// CPoint A;
	// CPoint C;

	 int Ax,Ay,Cx,Cy;
public:
	MShape();
	
	virtual bool isinshap(int x,int y);
	virtual void select(){}
	virtual void moved(){}
	virtual void Draw(CDC *dc){}
	virtual ~MShape(){}

	void Serialize (CArchive& ar);


	
	virtual int getR() {return R;}
	virtual int getG() { return G; }
	virtual int getB() { return B; }
	virtual int getAx() { return this->Ax; }
	virtual int getAy() { return this->Ay; }

	virtual int getCx() { return this->Cx; }
	virtual int getCy() { return this->Cy; }

	virtual void setR(int newR) { this->R = newR; }
	virtual void setG(int newG) { this->G = newG;; }
	virtual void setB(int newB) { this->B = newB; }

	virtual void setAx(int newAx){ this->Ax = newAx;}
	virtual void setAy(int newAy) { this->Ay = newAy; }
	virtual void setCx(int newCx) { this->Cx = newCx; }
	virtual void setCy(int newCy) { this->Cy = newCy; }
	
};

//#endif