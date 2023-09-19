#pragma once

#include <iostream>

// TODO: Add functionality

class GELoggerImguiConsole {
public:
	static void Info() {
		std::cout << "GE Info: " << std::endl;
	}
	static void Caution() {
		std::cout << "GE Caution: " << std::endl;
	}
	static void Warn() {
		std::cout << "GE Warn: " << std::endl;
	}
	static void Fatal() {
		std::cout << "GE Fatal: " << std::endl;
	}
};