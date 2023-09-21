#pragma once

#include <string>
#include <fmt/format.h>

class LoggerConsole {
public:
	static void Info(std::string arg_text) {
		fmt::println("VL: Info - {0}", arg_text);
	}
	static void Caution(std::string arg_text) {
		fmt::println("VL: Caution - {0}", arg_text);
	}
	static void Warn(std::string arg_text) {
		fmt::println("VL: Warn - {0}", arg_text);
	}
	static void Fatal(std::string arg_text) {
		fmt::println("VL: Fatal - {0}", arg_text);
	}
};