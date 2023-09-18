#pragma once

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include "GameProgramConfig.h"

/// <summary>
/// Example of game.cpp should look like
/// </summary>
class GameProgramExample {
private:
	GameProgramConfig m_gameProgramConfig;
public:
	GameProgramConfig Get_GameProgramConfig();
	void Start();
	void Update();
	void Terminate();
	void Gui_Start();
	void Gui_Update();
	void Gui_Terminate();
};
