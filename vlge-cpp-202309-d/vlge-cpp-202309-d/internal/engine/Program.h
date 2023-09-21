#pragma once

/*
Copyright 2023 Violetta Lappy - hoanglongplanner

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

#include "ProgramConfig.h"

#include "ProgramProcessor.h"
#include "ProgramEditor.h"
#include "ProgramRender.h"

#include "ProgramNetwork.h"

class Program {
private:
	ProgramConfig m_config;
	ProgramProcessor m_processor;
	ProgramEditor m_editor;
	ProgramRender m_render;
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
	void Awake();
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);	
	void Terminate();
};