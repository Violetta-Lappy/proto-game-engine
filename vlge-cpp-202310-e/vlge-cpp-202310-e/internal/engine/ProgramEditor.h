/*
Copyright 2023 Violetta & Lappy - hoanglongplanner

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