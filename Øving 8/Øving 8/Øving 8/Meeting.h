#pragma once

#include "std_lib_facilities.h"

enum class Campus by: int {
	Trondheim = 1, Gj�vik = 2
};


ostream& operator<<(ostream& os, const Campus& p);