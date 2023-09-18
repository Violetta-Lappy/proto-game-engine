#pragma once

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

/// <summary>
/// Example of game.cpp should look like
/// </summary>
class GameProgramExample {
public:
	void Start();
	void Update();
	void Terminate();
	void Gui_Start();
	void Gui_Update();
	void Gui_Terminate();
};
