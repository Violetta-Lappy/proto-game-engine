#pragma once

#include "ProgramConfig.h"

class ProgramNetwork {
private:
	ProgramConfig m_config;
public:
	ProgramNetwork();
	~ProgramNetwork();
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