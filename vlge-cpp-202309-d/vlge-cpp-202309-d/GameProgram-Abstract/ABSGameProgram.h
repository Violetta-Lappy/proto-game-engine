#pragma once

#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

class ABSGameProgram {
public:	
	virtual void Start();
	virtual void Update();
	virtual void Terminate();
	virtual void Gui_Start();
	virtual void Gui_Update();
	virtual void Gui_Terminate();
};