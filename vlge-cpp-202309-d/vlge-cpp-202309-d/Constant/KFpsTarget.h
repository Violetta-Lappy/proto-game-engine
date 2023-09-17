#pragma once

#include "../AppEngine/AELogger.h"

class KFpsTarget {
public:
	static const int K_144() {
		AELogger::Info();
		return 144;
	}
	static const int K_60() {
		AELogger::Info();
		return 60;
	}
	static const int K_30() {
		AELogger::Info();
		return 30;
	}
};