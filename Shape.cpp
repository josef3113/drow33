#include "stdafx.h"
#include "Shape.h"
				  


IMPLEMENT_SERIAL (MShape, CObject, 1)



MShape::MShape(){}


bool MShape ::isinshap(int x,int y)
{
	
		if( (x > this->Ax) && (x < this->Cx) && (y > this->Ay) && (y < this->Cy) )
			return true;
		else
			return false;
	
}



void MShape :: Serialize (CArchive& ar)
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
			
			
		}
	}