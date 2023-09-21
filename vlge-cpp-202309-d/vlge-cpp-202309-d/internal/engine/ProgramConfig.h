#pragma once

#include <string>
#include <fmt/format.h>

class ProgramConfig {
private:
	std::string str_programName = "Violetta Lappy Framework - Program Example - PLEASE CHANGE CONFIG IF SEE THIS";
	std::string str_programSpec = "Raylib OpenGL Windows x64";
	int i32_screenWidth = 1280; //def: 800
	int i32_screenHeight = 720; //def: 600
	int i32_targetFps = KFpsTarget::K_60; //def: 60
	int i32_refreshRate = KRefeshRate::K_30; //def: 30
public:
	ProgramConfig() {
	}
	~ProgramConfig() {
	}
public:
	void SetProgramName(std::string arg_name) {
		str_programName = arg_name;
	}
	void SetScreenWidth(int arg_value) {
		i32_screenWidth = arg_value;
	}
	void SetScreenHeight(int arg_value) {
		i32_screenHeight = arg_value;
	}	
	void SetTargetFps(int arg_value) {
		i32_targetFps = arg_value;
	}	
	void SetRefreshRate(int arg_value) {
		i32_refreshRate = arg_value;
	}
public:
	std::string GetProgramName() const {
		return fmt::format("{0} - {1}", str_programSpec, str_programName);
	}
	int GetScreenWidth() const {
		return i32_screenWidth;
	}
	int GetScreenHeight() const {
		return i32_screenHeight;
	}
	int GetTargetFps() const {
		return i32_targetFps;
	}
};