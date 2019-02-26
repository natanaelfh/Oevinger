#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

// This part is only relevant for non-Windows users in 2019.
// Windows users has Graph_lib::Arc, Mac don't.
#ifndef WIN32
#include "Graph_lib.h"
#endif

using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

// A yellow, empty face.
// An abstract class.
class Face : public Emoji
{

protected:
Circle face;

public:
	Face(Point c, int r);
	virtual void attach_to(Graph_lib::Window& win) override;
};

class Eye {
private:

	Circle eye;
public:
	Eye(Point c, int r);
	virtual void attach_to(Graph_lib::Window& win);
};


class EmptyFace
{
private:
	Face test;
	Eye leftEye;
	Eye rightEye;

public:
	EmptyFace(Point c, int r);
	void attach_to(Graph_lib::Window& win);
};

class SmilingMouth {
private:
	Arc mouth;
public:
	SmilingMouth(Point c);
	void attach_to(Graph_lib::Window& win);
};

class SadMouth {
private:
	Arc mouth;
public:
	SadMouth(Point c);
	void attach_to(Graph_lib::Window& win);
};


class SadFace {
private:
	EmptyFace blank;
	SadMouth mouth;
public:
	SadFace(Point c, int r);
	void attach_to(Graph_lib::Window& win);
};
/* TODO:
 *  - declare more emojis.
 **/
