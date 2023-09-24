#pragma once

//for Raylib only

#include "raylib.h"
#include "ProgramConfig.h"

class ProgramRender {
private:
	Camera3D camera = { 0 };
	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
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