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

SmilingEyes::SmilingEyes(Point c) : eye{ c,20,20,0,180} {
	eye.set_fill_color(Color::black);

}



void SmilingEyes::attach_to(Graph_lib::Window& win) {
	win.attach(this->eye);
}


AngryLines::AngryLines(Point s, Point e) :line{ s,e } {

	line.set_fill_color(Color::black);
}

void AngryLines::attach_to(Graph_lib::Window& win) {
	win.attach(this->line);
}


EmptyFace::EmptyFace(Point c, int r): test{ c, r }, leftEye{ Point{c.x - 10, c.y - 10},r / 5 }, rightEye{ Point{c.x + 10, c.y - 10},r / 5 } {

}

void EmptyFace::attach_to(Graph_lib::Window& win) {
	test.attach_to(win);
	leftEye.attach_to(win);
	rightEye.attach_to(win);
}


SmilingEmptyFace::SmilingEmptyFace(Point c, int r) : test{ c, r }, leftEye{ Point{c.x - 10, c.y - 10} }, rightEye{ Point{c.x + 10, c.y - 10}} {

}

void SmilingEmptyFace::attach_to(Graph_lib::Window& win) {
	test.attach_to(win);
	leftEye.attach_to(win);
	rightEye.attach_to(win);
}


SmilingMouth::SmilingMouth(Point c) :mouth{c, 50,50,170,370} {
	mouth.set_color(Color::black);
}
void SmilingMouth::attach_to(Graph_lib::Window& win) {
	win.attach(this->mouth);
}


SadMouth::SadMouth(Point c) :mouth{ Point{c.x, c.y + 40}, 50,50,10,170 } {
	mouth.set_color(Color::black);
	
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

SmilingFace::SmilingFace(Point c, int r) :blank{ c,r }, mouth{ c }{

}
void SmilingFace::attach_to(Graph_lib::Window& win) {
	blank.attach_to(win);
	mouth.attach_to(win);
}

SuperHappyFace::SuperHappyFace(Point c, int r) :blank{ c,r }, mouth{ c }{

}
void SuperHappyFace::attach_to(Graph_lib::Window& win) {
	blank.attach_to(win);
	mouth.attach_to(win);
}


SuperAngryFace::SuperAngryFace(Point c, int r) :blank{ c,r }, leftLine{ Point{c.x - 10 - r / 5, c.y - 15 - r / 5}, Point{c.x - 10 + r / 5, c.y - 15} }, rightLine{ Point{c.x + 10 - r / 5, c.y - 15},Point{c.x + 10 + r / 5, c.y - 15 - r / 5} }, mouth{ c } {

}
void SuperAngryFace::attach_to(Graph_lib::Window& win) {
	blank.attach_to(win);
	leftLine.attach_to(win);
	rightLine.attach_to(win);
	mouth.attach_to(win);

}

ScaredFace::ScaredFace(Point c, int r) :blank{ c,r }, leftLine{ Point{c.x - 10 - r / 5, c.y - 15 }, Point{c.x - 10 + r / 5, c.y - 15-r/5} }, rightLine{ Point{c.x + 10 - r / 5, c.y - 15-r/5},Point{c.x + 10 + r / 5, c.y - 15 } }, mouth{ c } {

}
void ScaredFace::attach_to(Graph_lib::Window& win) {
	blank.attach_to(win);
	leftLine.attach_to(win);
	rightLine.attach_to(win);
	mouth.attach_to(win);

}