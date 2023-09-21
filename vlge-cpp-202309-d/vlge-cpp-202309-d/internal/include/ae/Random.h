#pragma once

#include <raylib.h>

// TODO: Check functionality

class Random {
public:
	static int GetRandomInt() {
		return 0;
	}
	static int GetRandomInt(int arg_min, int arg_max) {
		return GetRandomValue(arg_min, arg_max);
	}
	static float GetRandomFloat(float arg_min, float arg_max) {
		return 0.0f;
	}
	//const double Get_RandomDouble();
};