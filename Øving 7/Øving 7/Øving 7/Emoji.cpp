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


EmptyFace::EmptyFace(Point c, int r): Face test{ c, emojiRadius } {
	;
	Eye lefteye{ Point{c.x - 10, c.y - 10},emojiRadius / 5 };
	Eye righteye{ Point{c.x + 10, c.y - 10},emojiRadius / 5 };
}
