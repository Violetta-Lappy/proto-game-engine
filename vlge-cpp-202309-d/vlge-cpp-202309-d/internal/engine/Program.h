#pragma once

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

#include "ProgramConfig.h"

#include "ProgramProcessor.h"
#include "ProgramEditor.h"
#include "ProgramRender.h"

#include "ProgramNetwork.h"

class Program {
private:
	ProgramConfig m_config;
	ProgramProcessor m_processor;
	ProgramEditor m_editor;
	ProgramRender m_render;
	ProgramNetwork m_network;	
public:
	Program();
	~Program();
public:
	ProgramConfig GetConfig() const {
		return m_config;
	}
	void SetupConfig();
public:
	void Awake();
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);	
	void Terminate();
};