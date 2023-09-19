#pragma once

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include "fmt/format.h"
#include "ENGINEProgramConfig.h"

#include "KProgramExitCode.h"

/// <summary>
/// Example of game.cpp should look like, deltatime, timestep
/// </summary>
class ENGINEProgram {
private:
	ENGINEProgramConfig m_config;
public:
	ENGINEProgramConfig Get_Config() {
		return m_config;
	};
	void Setup_Config();
public:
	void Start();
	void Update(float arg_deltaTime, float arg_unscaledDeltaTime);
	void Terminate();
	void Gui_Start();
	void Gui_Update(float arg_deltaTime, float arg_unscaledDeltaTime);
	void Gui_Terminate();
};
