#pragma once

#include "ProgramConfig.h"

class ProgramProcessor {
private:
	ProgramConfig m_config;
public:
	ProgramProcessor();
	~ProgramProcessor();
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