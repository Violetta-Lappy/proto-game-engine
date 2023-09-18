#pragma once

/// <summary>
/// Program Exit Code Status
/// </summary>
class KExitCode {
public:
	static const int K_Success() {				
		return 0;
	}
	static const int K_Fail() {				
		return -1;
	}
};