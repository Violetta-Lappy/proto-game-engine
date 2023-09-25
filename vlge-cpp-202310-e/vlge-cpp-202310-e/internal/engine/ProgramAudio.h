#pragma once

#include <raylib.h>
#include "ProgramConfig.h"

class ProgramAudio {
private:
	ProgramConfig m_config;
public:
	ProgramAudio();
	~ProgramAudio();
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
public:
	void PlayAudio();
	void Mixer();
};