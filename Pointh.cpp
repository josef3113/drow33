

#include "Pointh.h"


Point::Point(int x,int y)
{
	this->setX(x);
	this->setY(y);
}

Point::Point(const Point &other) //copy constractor
{
	(*this)=other;   //because no have pointer its ok to do this
}

Point::~Point()
{
}

//------getrs

int Point::getX()const
{
	return this->x;
}

int Point::getY()const
{
	return this->y;
}


//------setrs 

Point& Point::setX(int x)
{
	this->x=x;

	return (*this);
}

Point& Point::setY(int y)
{
	this->y=y;

	return (*this);
}

//------operator 
Point& Point::operator=(const Point& other)
{
	this->x=other.x;
	this->y=other.y;

	return (*this);
}



//------function of Point


double Point::getDistance(const Point & B)const
{

	double s=this->getX()-B.getX();     //  (X1-X2)
	double p=this->getY()-B.getY();     //  (Y1-Y2)



	return sqrt(s*s + p*p);        //sqrt of (x1-x2)^2 + (y1-y2)^2 is a distance between two point

}


//----friend function

ostream& operator <<(ostream &out,const Point& toprint)
{
	out<<"the point is:("<<toprint.x<<","<<toprint.y<<")";
	return out;
}