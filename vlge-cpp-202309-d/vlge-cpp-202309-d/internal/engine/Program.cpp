#include "Program.h"

Program::Program() {
	//Setup config before starting all services
	SetupConfig();
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
		m_config.Set_ProgramName("ENGINEProgram");
		m_config.Set_ScreenWidth(1280);
		m_config.Set_ScreenHeight(720);
		m_config.Set_TargetFps(KFpsTarget::K_60);
		m_config.Set_RefreshRate(KRefeshRate::K_30);
	}

	//Setup global config done
	fmt::println(GetConfig().Get_ProgramName());
	fmt::println("Violetta Lappy: Setup Global Config - DONE [O]");

	//Setup all services with common global config
	m_processor.SetConfig(GetConfig());
	m_editor.SetConfig(GetConfig());
	m_network.SetConfig(GetConfig());

	fmt::println("Violetta Lappy: Setup All Services with Global Config - DONE [O]");
}

void Program::Start() {	
	m_processor.Start();
	m_editor.Start();
	m_network.Start();
}

void Program::Update(float arg_dt, float arg_unscaledDt) {
	m_processor.Update(arg_dt, arg_unscaledDt);
	m_editor.Update(arg_dt, arg_unscaledDt);
	m_network.Update(arg_dt, arg_unscaledDt);
}

void Program::Terminate() {
	//everything must be reverse order
	m_network.Terminate();
	m_editor.Terminate();
	m_processor.Terminate();	
}
