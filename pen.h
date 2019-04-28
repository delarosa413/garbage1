#include <FL/fl_draw.H>
#include <vector>
#ifndef PEN_H
#define PEN_H

class pen
{
	public:
		pen();
		pen(double a, double b);
		
		double getX();
		double getY();
		
		void setY(double i);
		void setX(double i);
	
	private:
		int x, y;
};

#endif
