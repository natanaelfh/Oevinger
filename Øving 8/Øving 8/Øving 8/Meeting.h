#pragma once

#include "std_lib_facilities.h"

enum class Campus by: int {
	Trondheim = 1, Gjøvik = 2
};


ostream& operator<<(ostream& os, const Campus& p);