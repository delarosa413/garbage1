#include <FL/fl_draw.H>
#ifndef CIRCLE_H
#define CIRCLE_H

class circle
{
	public:
		circle(double r, int a, int px, int py);
		circle();
		//~circle();
		
		double getRadius();
		double getAngle();
		
		int getX();
		int getY();
		
		void setRadius(double i);
		void setAngle(double i);
		void setY(int i);
		void setX(int i);
		void draw();
		void update(int x);
	
	private:
		int x, y;
		double angle, radius;
		
};

#endif
