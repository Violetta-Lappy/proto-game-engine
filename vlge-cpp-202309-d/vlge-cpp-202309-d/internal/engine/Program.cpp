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

void Program::Start() {
	//--SETUP CONFIG & SUB SYSTEMS--
	SetupConfig();
	fmt::println(GetConfig().GetProgramName());
	fmt::println("Violetta Lappy: Setup Global Config - DONE [O]");

	m_processor.SetConfig(GetConfig());
	m_editor.SetConfig(GetConfig());
	fmt::println("Violetta Lappy: Setup All Services with Global Config - DONE [O]");

	m_editor.SetProcessor(m_processor);
	fmt::println("Violetta Lappy: Setup All Individual Services - DONE [O]");
	
	//--SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO--		
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(GetConfig().GetScreenWidth()
		, GetConfig().GetScreenHeight()
		, GetConfig().GetProgramName().c_str());
	SetTargetFPS(GetConfig().GetTargetFps());		
	rlImGuiSetup(true);

	//--ADD HERE--
	m_editor.Start();
}

void Program::Update(float arg_dt, float arg_unscaledDt) {
	BeginDrawing();
	ClearBackground(DARKGRAY);
	rlImGuiBegin();

	//Update all services here
	m_editor.Update(arg_dt, arg_unscaledDt);

	rlImGuiEnd();
	EndDrawing();
}

void Program::Terminate() {
	//Terminate system by reverse order
	m_editor.Terminate();
	
	//--SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO--
	rlImGuiShutdown();
	CloseWindow();

	fmt::println("Violetta Lappy: ENGINE Shutdown Success [O]");
}
