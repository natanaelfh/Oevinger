// Example program in TDT4102_Graphics template, from PPP page 415
#include "Graph.h"
#include "Simple_window.h" 
#include "std_lib_facilities.h"
#include "file.h"
#include "emne.h"
#include "temp.h"
int main() {
	vector<Temps> newTemp{ readTemp() };

	int max_temp{ 0 };
	int min_temp{ 0 };
	for (Temps t : newTemp) {
		if (t.max > max_temp) {
			max_temp = t.max;
		}
		if (t.min < min_temp) {
			min_temp = t.min;
		}
	}


	constexpr int xmax = 600; // window size
	constexpr int ymax = 400;
	constexpr int xoffset = 100; // distance from left-hand side of window to y axis
	constexpr int yoffset = 100; // distance from bottom of window to x axis
	constexpr int xspace = 40; // space beyond axis
	constexpr int yspace = 40;
	constexpr int xlength = (xmax - xoffset - xspace); // length of axes
	constexpr int ylength = (ymax - yoffset - yspace);

	int base_year = 0;
	int end_year = newTemp.size() - 1;

	double xscale = double(xlength) / (end_year-base_year);
	double yscale = double(ylength) / (max_temp - min_temp);

	class Scale { // data value to coordinate conversion
		int cbase; // coordinate base
		int vbase; // base of values
		double scale;
	public:
		Scale(int b, int vb, double s) :cbase{ b }, vbase{ vb }, scale{ s } { }
		int operator()(int v) const { return cbase + (v-vbase)*scale; } // see §21.4
	};

	Scale xs{ xoffset,base_year,xscale };
	Scale ys{ ymax-yoffset,0,-yscale };

	Graph_lib::Window win{ Point{100,100},xmax,ymax,"Temps" };

	Axis x {Axis::x,  Point{xoffset,ymax-yoffset}, xlength,(end_year-base_year) / 12,"Feb Mar Apr Mai Jun Aug Sept Okt Nov Des Jan" };
	x.set_color(Color::green);
	Axis y{ Axis::y, Point{xoffset,ymax-yoffset}, ylength, 6,"Temp" };

	Open_polyline min;
	Open_polyline max;
	int day{ 0 };
	int x1;
	for (Temps t : newTemp) {
		x1 = xs(day);
		min.add(Point{ x1, ys(t.min)});
		max.add(Point{ x1, ys(t.max)});
		day += 1;
	}

	min.set_color(Color::blue);
	max.set_color(Color::red);


	win.attach(min);
	win.attach(max);
	win.attach(x);
	win.attach(y);

	gui_main();
}

//temperatures.txt