#pragma once

#include "ProgramConfig.h"

//Dear Imgui and RmlUi

class ProgramEditor {
private:
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
public:
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);
	void Terminate();
};