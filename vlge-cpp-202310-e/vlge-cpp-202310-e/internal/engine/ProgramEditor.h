#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

#include <fmt/format.h>

#include "ProgramProcessor.h"
#include "ProgramConfig.h"

//Dear Imgui and RmlUi

class ProgramEditor {
private:
	mutable ProgramProcessor m_processor;
	mutable ProgramConfig m_config;		
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
	static void ShowWorkspaceScene(bool* arg_status);
	static void ShowWorkspaceGame(bool* arg_status);
	static void ShowOverlay(bool* arg_status);
	static void ShowAboutWindow(bool* arg_status);
	static void ShowContentDrawer(bool* arg_status);
};