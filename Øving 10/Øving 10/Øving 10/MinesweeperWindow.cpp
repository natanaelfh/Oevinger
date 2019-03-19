#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window(xy, width * cellSize, height*cellSize, title), width(width), height(height), mines(mines)
	//Initialiser medlemsvariabler, bruker også konstruktøren til Windowsklassen
{
	// Legg til alle tiles på vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click, false });
			attach(tiles.back());
		}
	}

	//Legg til miner på tilfeldige posisjoner


	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());


	//sier at tile 0 er en mine

	this->tiles[0].isMine = true;
	this->tiles[0].state = Cell::flagged;
	this->tiles[0].set_label("@<");
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	return 0;
};
vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	this->tiles[0].open();

}

void MinesweeperWindow::flagTile(Point xy) {
	this->tiles[0].flag();
}

//Kaller opentile ved venstreklikk og flagTile ved høyreklikk
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}


void MinesweeperWindow::setAdjMines(int n) {
	points
}
