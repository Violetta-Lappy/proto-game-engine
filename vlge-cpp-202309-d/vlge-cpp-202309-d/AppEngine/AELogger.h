#pragma once

#include <iostream>

class AELogger {
public:
	static void Info() {
		std::cout << "AE Info: " << std::endl;
	}
	static void Warn() {
		std::cout << "AE Warn: " << std::endl;
	}
	static void Fatal() {
		std::cout << "AE Fatal: " << std::endl;
	}
};