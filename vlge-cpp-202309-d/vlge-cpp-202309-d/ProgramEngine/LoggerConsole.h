#pragma once

#include <string>
#include <fmt/format.h>

class LoggerConsole {
public:
	static const void Info(std::string arg_text) {
		fmt::println("Info - {0}", arg_text);
	}
	static const void Caution(std::string arg_text) {
		fmt::println("Caution - {0}", arg_text);
	}
	static const void Warn(std::string arg_text) {
		fmt::println("Warn - {0}", arg_text);
	}
	static const void Fatal(std::string arg_text) {
		fmt::println("Fatal - {0}", arg_text);
	}
};