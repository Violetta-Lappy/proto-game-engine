#pragma once

#include <iostream>

class ABSLoggerImguiConsole {
public:
	virtual std::string Info() = 0;
	virtual std::string Caution() = 0;
	virtual std::string Warn() = 0;
	virtual std::string Fatal() = 0;
};