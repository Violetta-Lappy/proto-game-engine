#pragma once

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include <rmlui/Core.h>
#include <rmlui/Debugger.h>

#include "fmt/format.h"

#include "ProgramProcessor.h"
#include "ProgramConfig.h"

//Dear Imgui and RmlUi

class ProgramEditor {
private:
	ProgramProcessor m_processor;
	ProgramConfig m_config;
public:
	ProgramEditor();
	~ProgramEditor();
public:
	ProgramConfig GetConfig() const {
		return m_config;
	}
	void SetConfig(ProgramConfig arg_config) {
		m_config = arg_config;
	}
	void SetProcessor(ProgramProcessor arg_processor) {
		m_processor = arg_processor;
	}
public:
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);
	void Terminate();
private:
	static void ShowOverlay(bool* p_open);
};