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

#include "Program.h"

Program::Program() {		
}

Program::~Program() {		
}

void Program::SetupConfig() {
	bool canIniLoadSuccess = false;
	if (canIniLoadSuccess) {
		//setup if detect file
		// TODO: if detect programconfig.ini, set up
	}
	else {
		m_config.SetProgramName("ENGINEProgram");
		m_config.SetScreenWidth(1600);
		m_config.SetScreenHeight(900);
		m_config.SetTargetFps(KFpsTarget::K_60);
		m_config.SetRefreshRate(KRefeshRate::K_30);
	}	
}

void Program::Init() {
	//--SETUP CONFIG & SUB SYSTEMS--
	SetupConfig();	

	fmt::println(GetConfig().GetProgramName());
	fmt::println("Violetta Lappy: Setup Global Config - DONE [O]");	
}

void Program::Run(float arg_dt, float arg_unscaledDt) {	
	
}

void Program::Close() {		
	//--SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO--	

	fmt::println("Violetta Lappy: ENGINE Shutdown Success [O]");
}
