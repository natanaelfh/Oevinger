#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window(xy, width * cellSize, height*cellSize, title), width(width), height(height), mines(mines)
	//Initialiser medlemsvariabler, bruker også konstruktøren til Windowsklassen
{
	this->opened = 0;
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
	vector<int> minepos;
	for (int i = 0; i < (width*height); i++) {
		minepos.push_back(i);
	}
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(minepos.begin(), minepos.end(), default_random_engine(seed));

	for (int i = 0; i < mines; i++) {
		this->tiles[minepos[i]].isMine = true;
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());

	////sier at tile 0 er en mine

	//this->tiles[0].isMine = true;
	//this->tiles[0].state = Cell::flagged;
	//this->tiles[0].set_label("@<");
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int i = 0;
	
	for (auto point : points) {
		const Tile& t = at(point);
		if (t.isMine == true) {
			i = i + 1;
		}
	}

	return i;
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
	Tile& t = at(xy);
	if (t.state == Cell::closed) {
		t.open();
		if (t.isMine == false) {
			this->opened = this->opened + 1;
			vector<Point> points = adjacentPoints(xy);
			int num = countMines(points);
			if (num > 0) {
				t.setAdjMines(num);
			}
			else {
				for (Point p : points) {
					openTile(p);
				}
			}
		}
		else
		{
			//game has ended loose
			

			hide();
		}
	}
	if (this->opened == (width*height - mines)) {

		//In_box text{ Point{50,50},50,20,"YOU WON" };

	}
}

void MinesweeperWindow::flagTile(Point xy) {
	Tile& t = at(xy);
	if (t.state == Cell::closed || t.state == Cell::flagged) {
		t.flag();
	}
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

