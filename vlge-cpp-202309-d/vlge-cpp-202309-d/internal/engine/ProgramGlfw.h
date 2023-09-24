#pragma once

#include <GLFW/glfw3.h>

#include "ProgramConfig.h"

#include "ProgramProcessor.h"
#include "ProgramEditor.h"
#include "ProgramRender.h"

#include "ProgramAudio.h"
#include "ProgramNetwork.h"

class ProgramGlfw {
private:
	ProgramConfig m_config;
	ProgramProcessor m_processor;
	ProgramEditor m_editor;
	ProgramRender m_render;
	//ProgramAudio m_audio;
	//ProgramNetwork m_network;	
public:
	ProgramGlfw();
	~ProgramGlfw();
public:
	ProgramConfig GetConfig() const {
		return m_config;
	}
	void SetupConfig();
public:
	void Init();
	void Run(float arg_dt, float arg_unscaledDt);
	void Close();
};