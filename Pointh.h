#ifndef POINT_H
#define POINT_H

#include<iostream>
using namespace std;

class Point
{
private:
	int x, y;

public:

	Point(int x=0, int y=0);   //defult constractor
	Point(const Point&);       //copy constractor
	~Point();

	//-----getrs

	int getX() const;
	int getY() const;

	//-----setrs

	Point& setX(int x);
	Point& setY(int y);
	
	//function of Point 
	double getDistance(const Point &B)const;
	
	//-----operator

	Point& operator =(const Point& other);
	
	//friend function

	friend ostream& operator <<(ostream &out,const Point & toprint);

};



#endif