#ifndef LINE_H
#define LINE_H

#include "stdafx.h"
#include "Shape.h"



class MYLine :public MShape
{

	DECLARE_SERIAL (MYLine)

private:
	int sizeLpen;

public:
	

	MYLine(int Ax , int Ay,int Cx,int Cy,int R,int G,int B,int sizeLpen );  //difult constractor
	~MYLine();
	MYLine(){}

	void Draw(CDC *dc);
	bool isinshap(int x,int y){return false;}
	void select(){};
	void moved(){};
	
	void setSizeLpen(int newSizeLpen) { this->sizeLpen = newSizeLpen; }
	int getSizeLpen() { return this->sizeLpen; }

	void Serialize (CArchive& ar)
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
	


};

#endif