#pragma once

//for Raylib only

#include "ProgramConfig.h"

class ProgramRender {
private:
	ProgramConfig m_config;
public:
	ProgramRender();
	~ProgramRender();
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