#pragma once


class MShape: public CObject 
{
	
	DECLARE_SERIAL (MShape)
protected:
	
	 int R,G,B;
	 int Ax,Ay,Cx,Cy;

public:

	MShape(){};
	virtual ~MShape(){}
	
	virtual bool isinshap(int x,int y);
	virtual void select(){}
	virtual void moved(){}
	virtual void Draw(CDC *dc){}
	

	void Serialize (CArchive& ar);


	 //-----getrs
	int getR() {return R;}
	int getG() { return G; }
    int getB() { return B; }
	int getAx() { return this->Ax; }
	int getAy() { return this->Ay; }
	int getCx() { return this->Cx; }
	int getCy() { return this->Cy; }

	//---setrs 

	void setR(int newR) { this->R = newR; }
	void setG(int newG) { this->G = newG;; }
	void setB(int newB) { this->B = newB; }
	void setAx(int newAx){ this->Ax = newAx;}
	void setAy(int newAy) { this->Ay = newAy; }
	void setCx(int newCx) { this->Cx = newCx; }
	void setCy(int newCy) { this->Cy = newCy; }
	
};
