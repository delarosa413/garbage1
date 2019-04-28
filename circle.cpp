#include <FL/fl_draw.H>
#include "circle.h"

circle::circle(double r, int a, int px, int py)
{
	radius=r;
	angle=a;
	x=px;
	y=py;
}

circle::circle()
{
	radius=10.0;
	angle=0;
	x=0;
	y=0;
}
		
double
circle::getRadius()
{
	return radius;
}

double
circle::getAngle()
{
	return angle;
}

int
circle::getX()
{
	return x;
}

int
circle::getY()
{
	return y;
}

void
circle::setRadius(double i)
{
	radius=i;
}

void 
circle::setAngle(double i)
{
	angle=i;
}

void
circle::setX(int i)
{
	x=i;
}

void 
circle::setY(int i)
{
	y=i;
}

void
circle::draw()
{
	fl_push_matrix();
	fl_color(FL_WHITE);
	//fl_translate(x,y);
	/*
	fl_begin_line();
	fl_arc( this->x, this->y, this->radius, 0.0, 360.0);
	fl_end_line();
	*/
	fl_begin_line();
	fl_circle(this->x,this->y,this->radius);
	fl_end_line();
		
	fl_pop_matrix();
	
}

void
circle::update(int x)
{
	angle=angle+x;
	if (angle>360){
		angle=angle-360;
	}
}
