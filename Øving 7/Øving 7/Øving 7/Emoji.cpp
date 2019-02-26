#include "Emoji.h"

/*
 * Implement your emojis in this file.
 **/


// A yellow, empty face.
Face::Face(Point c, int r) : face{ c,r }
{
	/* TODO:
	 *  - add member initializer list
	 *  - implement the constructor. I.e. fill color
	 **/
	//face = Circle(c, r);
	face.set_fill_color(Color::yellow);


}


void Face::attach_to(Graph_lib::Window& win)
{
	/* TODO:
	 *  - attach shapes to window
	 **/

	win.attach(this->face);


}

/* TODO:
 *  - define more emojis.
 **/

Eye::Eye(Point c, int r) : eye{c,r } {
	eye.set_fill_color(Color::dark_gray);
	
}


void Eye::attach_to(Graph_lib::Window& win) {
	win.attach(this->eye);
}


EmptyFace::EmptyFace(Point c, int r): test{ c, r }, leftEye{ Point{c.x - 10, c.y - 10},r / 5 }, rightEye{ Point{c.x + 10, c.y - 10},r / 5 } {

}

void EmptyFace::attach_to(Graph_lib::Window& win) {
	test.attach_to(win);
	leftEye.attach_to(win);
	rightEye.attach_to(win);
}


SmilingMouth::SmilingMouth(Point c) :mouth{c, 50,50,-10,10} {
	
}
void SmilingMouth::attach_to(Graph_lib::Window& win) {
	win.attach(this->mouth);
}


SadMouth::SadMouth(Point c) :mouth{ c, 50,50,10,170 } {

}
void SadMouth::attach_to(Graph_lib::Window& win) {
	win.attach(this->mouth);
}


SadFace::SadFace(Point c, int r) :blank{ c,r }, mouth{ c }{

}
void SadFace::attach_to(Graph_lib::Window& win) {
	blank.attach_to(win);
	mouth.attach_to(win);
}
