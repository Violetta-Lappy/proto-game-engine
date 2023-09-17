#pragma once

#include <iostream>

class GELogger {
public:
	static void Info() {
		std::cout << "GE Info: " << std::endl;
	}
	static void Warn() {
		std::cout << "GE Warn: " << std::endl;
	}
	static void Fatal() {
		std::cout << "GE Fatal: " << std::endl;
	}
};