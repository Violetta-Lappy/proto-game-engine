#pragma once

#include "../AppEngine/AELogger.h"

class KExitCode {
public:
	static const int K_Success() {		
		AELogger::Info();
		return 0;
	}
	static const int K_Fail() {		
		AELogger::Fatal();
		return -1;
	}
};