#include "GameProgramExample.h"

GameProgramConfig GameProgramExample::Get_GameProgramConfig() {
	m_gameProgramConfig.Set_ProgramName("Violetta Lappy - Game Example");
	m_gameProgramConfig.Set_ScreenWidth(1280);
	m_gameProgramConfig.Set_ScreenHeight(720);
	m_gameProgramConfig.Set_TargetFps(KFpsTarget::K_60);
	m_gameProgramConfig.Set_RefreshRate(KRefeshRate::K_30);
	return m_gameProgramConfig;
}

void GameProgramExample::Start() {
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

	InitWindow(Get_GameProgramConfig().Get_ScreenWidth()
		, Get_GameProgramConfig().Get_ScreenHeight()
		, Get_GameProgramConfig().Get_ProgramName().c_str());

	SetTargetFPS(60);

	Gui_Start();
}

void GameProgramExample::Update() {
	BeginDrawing();
	ClearBackground(DARKGRAY);

	//Update Gui
	Gui_Update();

	EndDrawing();
}

void GameProgramExample::Terminate() {
	Gui_Terminate();
	CloseWindow();
}

void GameProgramExample::Gui_Start() {
	rlImGuiSetup(true);
}

void GameProgramExample::Gui_Update() {
	// start ImGui Conent
	rlImGuiBegin();
	// show ImGui Content
	bool open = true;
	ImGui::ShowDemoWindow(&open);
	// end ImGui Content
	rlImGuiEnd();
}

void GameProgramExample::Gui_Terminate() {
	rlImGuiShutdown();
}
