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
		m_config.SetScreenWidth(1280);
		m_config.SetScreenHeight(720);
		m_config.SetTargetFps(KFpsTarget::K_60);
		m_config.SetRefreshRate(KRefeshRate::K_30);
	}	
}

void Program::Awake() {
	//Prepare config file
	SetupConfig();
	fmt::println(GetConfig().GetProgramName());
	fmt::println("Violetta Lappy: Setup Global Config - DONE [O]");	
	fmt::println("Violetta Lappy: Setup All Services with Global Config - DONE [O]");
	fmt::println("Violetta Lappy: Setup All Individual Services - DONE [O]");
}

void Program::Start() {
	//--SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO--	
	//Setup raylib context
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(GetConfig().GetScreenWidth()
		, GetConfig().GetScreenHeight()
		, GetConfig().GetProgramName().c_str());
	SetTargetFPS(GetConfig().GetTargetFps());		
	rlImGuiSetup(true);
}

void Program::Update(float arg_dt, float arg_unscaledDt) {
	BeginDrawing();
	ClearBackground(DARKGRAY);
	rlImGuiBegin();

	m_editor.Update(arg_dt, arg_unscaledDt);

	rlImGuiEnd();
	EndDrawing();
}

void Program::Terminate() {
	rlImGuiShutdown();
	CloseWindow();
}
