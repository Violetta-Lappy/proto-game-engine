#pragma once

#include <raylib.h>

// TODO: Check functionality

class PROGRandom {
public:
	static const int Get_RandomInt(int arg_min, int arg_max) {
		return GetRandomValue(arg_min, arg_max);
	}
	static const float Get_RandomFloat(float arg_min, float arg_max) {
		return 0.0f;
	}
	//const double Get_RandomDouble();
};