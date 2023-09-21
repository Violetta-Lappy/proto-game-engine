#include "Program.h"

Program::Program() {	
}

Program::~Program() {
	//everything must be reverse order
	m_network.Terminate();
	m_render.Terminate();
	m_editor.Terminate();
	m_processor.Terminate();

	//SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO	
	rlImGuiShutdown();
	CloseWindow();
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
}

void Program::Awake() {
	//Prepare config file
	SetupConfig();
	fmt::println(GetConfig().Get_ProgramName());
	fmt::println("Violetta Lappy: Setup Global Config - DONE [O]");

	//Setup all services with common global config
	m_processor.SetConfig(GetConfig());
	m_editor.SetConfig(GetConfig());
	m_render.SetConfig(GetConfig());
	m_network.SetConfig(GetConfig());	
	fmt::println("Violetta Lappy: Setup All Services with Global Config - DONE [O]");

	//Setup individual services
	m_editor.SetProcessor(m_processor);	
	fmt::println("Violetta Lappy: Setup All Individual Services - DONE [O]");
}

void Program::Start() {
	//--SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO--	
	//Setup raylib context
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(GetConfig().Get_ScreenWidth()
		, GetConfig().Get_ScreenHeight()
		, GetConfig().Get_ProgramName().c_str());
	SetTargetFPS(GetConfig().Get_TargetFps());
	//SetupImgui
	rlImGuiSetup(true);
	
	//Start program services
	m_processor.Start();
	m_editor.Start();
	m_render.Start();
	m_network.Start();
}

void Program::Update(float arg_dt, float arg_unscaledDt) {
	//SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO	
	BeginDrawing();
	rlImGuiBegin();

	//Update all services
	m_processor.Update(arg_dt, arg_unscaledDt);
	m_editor.Update(arg_dt, arg_unscaledDt);
	m_render.Update(arg_dt, arg_unscaledDt);
	m_network.Update(arg_dt, arg_unscaledDt);

	//SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO	
	rlImGuiEnd();
	EndDrawing();
}

void Program::Terminate() {
	~Program();
}
