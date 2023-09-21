#pragma once

#include "ProgramConfig.h"
#include "ProgramProcessor.h"
#include "ProgramEditor.h"

#include "ProgramNetwork.h"

class Program {
private:
	ProgramConfig m_config;
	ProgramProcessor m_processor;
	ProgramEditor m_editor;
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
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);
	void Terminate();
};