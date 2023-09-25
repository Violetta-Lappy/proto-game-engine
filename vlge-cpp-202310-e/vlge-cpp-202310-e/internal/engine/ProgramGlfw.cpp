#include "ProgramGlfw.h"

ProgramGlfw::ProgramGlfw() {
}

ProgramGlfw::~ProgramGlfw() {
}

void ProgramGlfw::SetupConfig() {
	bool canIniLoadSuccess = false;
	if (canIniLoadSuccess) {
		//setup if detect file
		//TODO: if detect config.ini, set up
		//TODO: if detect config.csv, set up
	}
	else {
		m_config.SetProgramName("Glfw Program");
		m_config.SetScreenWidth(1280);
		m_config.SetScreenHeight(720);
		m_config.SetTargetFps(KFpsTarget::K_60);
		m_config.SetRefreshRate(KRefeshRate::K_30);
	}
}

void ProgramGlfw::Init() {
	//--SETUP CONFIG & SUB SYSTEMS--
	SetupConfig();
	fmt::println(GetConfig().GetProgramName());
	fmt::println("Violetta Lappy: Setup Global Config [O]");

	m_processor.SetConfig(GetConfig());
	m_editor.SetConfig(GetConfig());
	m_render.SetConfig(GetConfig());
	fmt::println("Violetta Lappy: Setup All Services with Global Config [O]");

	m_editor.SetProcessor(m_processor);
	fmt::println("Violetta Lappy: Setup All Individual Services [O]");

	//--SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO--		
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(GetConfig().GetScreenWidth()
		, GetConfig().GetScreenHeight()
		, GetConfig().GetProgramName().c_str());
	SetTargetFPS(GetConfig().GetTargetFps());
	rlImGuiSetup(true);

	//--ADD HERE--
	m_processor.Start();
	m_editor.Start();
	m_render.Start();
}

void ProgramGlfw::Run(float arg_dt, float arg_unscaledDt) {
	BeginDrawing();
	rlImGuiBegin();

	//Update all services here	
	m_processor.Update(arg_dt, arg_unscaledDt);
	m_editor.Update(arg_dt, arg_unscaledDt);
	m_render.Update(arg_dt, arg_unscaledDt);

	rlImGuiEnd();
	EndDrawing();
}

void ProgramGlfw::Close() {
	//Terminate system by reverse order
	m_render.Terminate();
	m_editor.Terminate();
	m_processor.Terminate();

	//--SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO--
	rlImGuiShutdown();
	CloseWindow();

	fmt::println("Violetta Lappy: ENGINE Shutdown [O]");
}
