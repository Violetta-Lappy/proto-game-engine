#pragma once

#include <string>
#include <fmt/format.h>

#include <ae/KFpsTarget.h>
#include <ae/KRefreshRate.h>

#define VIOLETTALAPPY_RELEASE "D"
#define VIOLETTALAPPY_YEARMONTH 202309
#define VIOLETTALAPPY_VERSION "0.0.0"
#define VIOLETTALAPPY_GRAPHIC "OpenGL 4.6 (GLFW + GLAD), Vulkan, WebGPU"

class ProgramConfig {
private:
	std::string str_programName = "Violetta Lappy Framework - Program Example - PLEASE CHANGE CONFIG IF SEE THIS";
	std::string str_programSpec = "Raylib OpenGL Windows x64";
	int i32_screenWidth = 1280; //def: 800
	int i32_screenHeight = 720; //def: 600
	int i32_targetFps = KFpsTarget::K_60; //def: 60
	int i32_refreshRate = KRefeshRate::K_30; //def: 30
	int i32_dpi = 1;
public:
	ProgramConfig() {
	}
	~ProgramConfig() {
	}
public:
	//--GLOBAL CONFIG--
	void SetProgramName(std::string arg_name) {
		str_programName = arg_name;
	}
	//--PROGRAM SYSTEM CONFIG--
	void SetTargetFps(int arg_value) {
		i32_targetFps = arg_value;
	}
	void SetRefreshRate(int arg_value) {
		i32_refreshRate = arg_value;
	}
	//--DISPLAY CONFIG--
	void SetScreenWidth(int arg_value) {
		i32_screenWidth = arg_value;
	}
	void SetScreenHeight(int arg_value) {
		i32_screenHeight = arg_value;
	}		
	void SetDpi(int arg_value) {
		i32_dpi = arg_value;
	}
	//--GRAPHIC CONFIG--
	//--OPENGL RENDER CONFIG--
	//--AUDIO CONFIG--
public:
	std::string GetProgramName() {
		return fmt::format("{0} - {1}", str_programSpec, str_programName);
	}
	int GetScreenWidth() const {
		return i32_screenWidth;
	}
	int GetScreenHeight() const {
		return i32_screenHeight;
	}
	int GetDpi() const {
		return i32_dpi;
	}
	int GetTargetFps() const {
		return i32_targetFps;
	}
};