#pragma once

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include "fmt/format.h"
#include "ENGINEProgramConfig.h"

#include "KProgramExitCode.h"

/// <summary>
/// Example of gui for program
/// </summary>
class ENGINEProgramGui {
public:
	ENGINEProgramGui();
	~ENGINEProgramGui();
private:
	mutable ENGINEProgramConfig m_config;
public:
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);
	void Terminate();	
private:
	static void GuiShowOverlay(bool* p_open);
};
