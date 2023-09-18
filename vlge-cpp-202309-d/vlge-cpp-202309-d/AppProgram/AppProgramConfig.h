#pragma once

#include <string>
#include "../Constant/KFpsTarget.h"
#include "../Constant/KRefreshRate.h"

class AppProgramConfig {
private:
	std::string str_programName = "GameProgramExample";
	std::string str_programSpec = "Raylib OpenGL Windows x64";
	int i32_screenWidth = 800; //def: 800
	int i32_screenHeight = 600; //def: 600
	int i32_targetFps = KFpsTarget::K_60; //def: 60
	int i32_refreshRate = KRefeshRate::K_30; //def: 30
public:
	AppProgramConfig() {
	}
	~AppProgramConfig() {
	}
public:
	void Set_ProgramName(std::string arg_name) {
		str_programName = arg_name;
	}
	void Set_ScreenWidth(int arg_value) {
		i32_screenWidth = arg_value;
	}
	void Set_ScreenHeight(int arg_value) {
		i32_screenHeight = arg_value;
	}
	/// <summary>
	/// Please use constant class KFpsTarget
	/// </summary>
	void Set_TargetFps(int arg_value) {
		i32_targetFps = arg_value;
	}
	/// <summary>
	/// Please use constant class KRefreshRate
	/// </summary>
	void Set_RefreshRate(int arg_value) {
		i32_refreshRate = arg_value;
	}
public:
	std::string Get_ProgramName() {
		return str_programName;
	}
	int Get_ScreenWidth() {
		return i32_screenWidth;
	}
	int Get_ScreenHeight() {
		return i32_screenHeight;
	}
	int Get_TargetFps() {
		return i32_targetFps;
	}
};