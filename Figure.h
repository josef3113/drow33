#pragma once

class Figure
{
protected:
public:
	int x1,y1,x2,y2;
	// CBrush b;
	Figure(void);
	Figure(int xx1,int yy1, int xx2, int yy2)
	{
		x1=xx1;
		x2=xx2;
		y1=yy1;
		y2=yy2;
	}
	virtual void Draw(CDC *dc)=0;
	virtual ~Figure(void);
};

class RectangleM:public Figure{
public:
	RectangleM(int xx1,int yy1, int xx2, int yy2)
		:Figure(xx1,yy1,xx2,yy2)
	{
		//this->b=b;
	}
	void Draw(CDC *dc)
	{
		// dc->SelectObject(&b);
		dc->Rectangle(x1,y1,x2,y2);
	}
};
class EllipseM:public Figure{
public:
	EllipseM(int xx1,int yy1, int xx2, int yy2)
		:Figure(xx1,yy1,xx2,yy2)
	{
		//this->b=b;
	}
	void Draw(CDC *dc)
	{
		 //dc->SelectObject(&b);
		dc->Ellipse(x1,y1,x2,y2);
	}
};