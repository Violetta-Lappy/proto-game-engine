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
	mutable ENGINEProgramConfig m_config;
public:
	/// <summary>
	/// Get usage only, not for set usage !!
	/// </summary>	
	ENGINEProgramConfig GetConfig() const {
		return m_config;
	};	
	void SetupConfig();
public:
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);
	void Terminate();
	void GuiStart();
	void GuiUpdate(float arg_dt, float arg_unscaledDt);
	void GuiTerminate();
private:
	static void Gui_ShowOverlay(bool* p_open);
};
