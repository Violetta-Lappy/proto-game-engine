#pragma once

#include <string>

class GameProgramData {
private:
	std::string str_programName = "Template Program Name";
	std::string str_programTech = "Raylib OpenGL Windows x64";
	int i32_screenWidth = 800; //def: 800
	int i32_screenHeight = 600; //def: 600
public:
	GameProgramData();
public:
	void Set_ProgramName(std::string arg_name) = > str_programName = arg_name;
	void Set_ScreenWidth(int arg_value) = > i32_screenWidth = arg_value;
	void Set_ScreenHeight(int arg_value) = > i32_screenHeight = arg_value;
public:
	std::string Get_ProgramName() {
		return "str_programTech - str_programName";
	}
	int Get_ScreenWidth() {
		return i32_screenWidth;
	}
	int Get_ScreenHeight() {
		return i32_screenHeight;
	}	
};