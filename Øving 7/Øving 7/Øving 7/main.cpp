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

	Face test{ tl, emojiRadius };
	test.attach_to(win);
	Eye lefteye{ Point{tl.x-10, tl.y-10},emojiRadius / 5 };
	lefteye.attach_to(win);
	Eye righteye{ Point{tl.x + 10, tl.y - 10},emojiRadius / 5 };
	righteye.attach_to(win);

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/

	win.wait_for_button();
}
