#include "Simple_window.h"
#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	SmilingFace face{ tl, emojiRadius };
	face.attach_to(win);

	SadFace sad{ Point{tl.x + 2*emojiRadius, tl.y}, emojiRadius };
	sad.attach_to(win);

	SuperHappyFace happy{ Point{tl.x + 4 * emojiRadius, tl.y}, emojiRadius };
	happy.attach_to(win);

	SuperAngryFace angry{ Point{tl.x + 6 * emojiRadius, tl.y}, emojiRadius };
	angry.attach_to(win);

	ScaredFace scared{ Point{tl.x + 8 * emojiRadius, tl.y}, emojiRadius };
	scared.attach_to(win);

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/

	win.wait_for_button();
}
