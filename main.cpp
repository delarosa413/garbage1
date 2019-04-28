//Demonstrate complex shapes
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include "time.h"
#include "pen.h"
#include "circle.h"
#include <vector>
#include <cmath>
int w=800;
int h=800;



using namespace std;

class bg : public Fl_Widget
{
public:
    bg(int x, int y, int w, int h) : Fl_Widget(x,y,w,h) 
    { 
		vector<circle> poop;
		vector<pen> dots;
		shh c=G;
    }
    
    handle(int e)
    {
		if(e==FL_KEYDOWN){
			if(Fl::event_key() == 'q'){
				poop[0].setRadius(poop[0].getRadius()+5);
			}else if(Fl::event_key() == 'e'){
				poop[0].setRadius(poop[0].getRadius()-5);
			}else if(Fl::event_key() == 'i'){
				poop[1].setRadius(poop[1].getRadius()+5);
			}else if(Fl::event_key() == 'p'){
				poop[1].setRadius(poop[1].getRadius()-5);
			}else if(Fl::event_key() == ' '){
				poop.clear();
				dots.clear();
			}
			
		}else if(e==FL_RELEASE){
			pause= (not pause);
		}
	}

    virtual void draw()
    {

        fl_color(FL_BLACK);
        fl_rectf(x(), y(), w(), h());
        fl_color(FL_WHITE);
        fl_push_matrix();
        fl_translate(w()/2,h()/2);
        if(poop.size() == 0){
			poop.push_back (circle(100, 0, 0, 0));
			poop.push_back (circle(50, 0, 0, 0));
		}
        for (int i=0; i<poop.size(); i++)
        {
			
			if(poop.size()-i != 1){
				poop[i].draw();
				fl_rotate(poop[i].getAngle());
				fl_translate(0,poop[i].getRadius()+poop[i+1].getRadius());
				}else{
					poop[i].draw();
					
				}
			if(pause){
				poop[i].update(1);
			}
			
			
		}
		fl_pop_matrix();
		
		int al=0,be=0;
		al=w()/2;
		be=h()/2;
		for (int i=0; i<poop.size(); i++)
		{
			if(poop.size()-i != 1){
				//fl_line(al,be,al+((poop[i].getRadius() + poop[i+1].getRadius())*sin(poop[i].getAngle()*3.141592/180)),be+((poop[i].getRadius() + poop[i+1].getRadius())*cos(poop[i].getAngle()*3.141592/180)));
				al=al+((poop[i].getRadius() + poop[i+1].getRadius())*sin(poop[i].getAngle()*3.141592/180));
				be=be+((poop[i].getRadius() + poop[i+1].getRadius())*cos(poop[i].getAngle()*3.141592/180));
			}else{
				//fl_rotate(poop[i].getAngle());
				//fl_line(al,be,al+((poop[i].getRadius())*sin((poop[i].getAngle()+poop[i-1].getAngle())*3.141592/180)),be+((poop[i].getRadius())*cos((poop[i].getAngle()+poop[i-1].getAngle())*3.141592/180)));
				al=al+((poop[i].getRadius())*sin((poop[i].getAngle()+poop[i-1].getAngle())*3.141592/180));
				be=be+((poop[i].getRadius())*cos((poop[i].getAngle()+poop[i-1].getAngle())*3.141592/180));
				//fl_rotate(-1*poop[i].getAngle());
				if(pause){
					dots.push_back(pen(al,be));
				}			
			}
		}
		
		
		switch(c)
{
    case R : fl_color(FL_RED);     break;
    case Y : fl_color(FL_YELLOW);  break;
    case G : fl_color(FL_GREEN);   break;
    case C : fl_color(FL_CYAN);    break;
    case B : fl_color(FL_BLUE);    break;
    case M : fl_color(FL_MAGENTA); break;
}
		fl_begin_line();
		
		for(int i=0; i<dots.size(); i++)
		{

				fl_vertex(dots[i].getX(),dots[i].getY());

				

		}
		
		
		fl_end_line();
		
        /*
        fl_push_matrix();
					fl_rotate(poop[i].getAngle());
					fl_translate(0,poop[i].getRadius());
					dots.push_back (steve.getX());
		dots.push_back (steve.getY());
					fl_pop_matrix();
        */
        
        
    }

private:

	vector<circle> poop;
	vector<pen> dots;
	bool pause;
	enum shh{R,Y,G,C,B,M};
	shh c=Y;
};

void update_frame(void *ptr)
{
    //set up the next frame
    Fl::repeat_timeout(1.0/24.0, update_frame, ptr);

    //redraw our box
    ((bg*)ptr)->redraw();
}

int main(int argc, char **argv)
{
	srand(time(0));
    Fl_Double_Window *window = new Fl_Double_Window(w, h, "shhh");
    bg *box = new bg(0, 0, w, h);

    //start the animation
    Fl::add_timeout(1.0/24.0, update_frame, box);

    window->show(argc, argv);
    Fl::run();
}
