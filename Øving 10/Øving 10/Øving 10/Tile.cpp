#include "Tile.h"

// For å sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{ {1, Color::blue},
								   {2, Color::red},
								   {3,Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow} };

// For å sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{ {Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"} };

void Tile::open()
{
	
	if (this->state == Cell::flagged) {
		return;
	}
	if (this->state == Cell::closed) {
		static_cast<Fl_Button*>(pw)->set();//Setter en button som trykket på, tilsvarer åpnet rute
	}
	if (this->isMine == true) {
		this->set_label("X");
		this->set_label_color(Color::red);
	}
}

void Tile::flag()
{
	if (this->state == Cell::flagged) {
		this->state = Cell::closed;
		this->set_label(cellToSymbol.at(Cell::closed));

		return;
	}
	if (this->state == Cell::closed) {
		this->state = Cell::flagged;
		this->set_label(cellToSymbol.at(Cell::flagged));
		this->set_label_color(Color::blue);

		return;
	}
}

