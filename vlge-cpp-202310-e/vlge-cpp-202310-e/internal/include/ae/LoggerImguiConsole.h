#pragma once

#include <string>
#include <fmt/format.h>
#include <fmt/printf.h>

// TODO: Add functionality

class LoggerImguiConsole {
public:
	static const void Info(std::string arg_text) {
		fmt::printf(arg_text);
	}
	static const void Caution(std::string arg_text) {
		fmt::printf(arg_text);
	}
	static const void Warn(std::string arg_text) {
		fmt::printf(arg_text);
	}
	static const void Fatal(std::string arg_text) {
		fmt::printf(arg_text);
	}
};