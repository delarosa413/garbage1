#include <FL/fl_draw.H>
#include "pen.h"
#include <vector>

pen::pen()
{
	x=0;
	y=0;
}
pen::pen(double a, double b)
{
	x=a;
	y=b;
}

double
pen::getX()
{
	return x;
}

double
pen::getY()
{
	return y;
}

void
pen::setX(double i)
{
	x=i;
}

void 
pen::setY(double i)
{
	y=i;
}

