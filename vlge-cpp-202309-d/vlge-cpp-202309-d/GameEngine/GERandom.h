#pragma once

#include "raylib.h"

// TODO: Implement Random Functionality

class GERandom {
public:
	static int Get_Random(int arg_min, int arg_max) {
		return GetRandomValue(arg_min, arg_max);
	}
};