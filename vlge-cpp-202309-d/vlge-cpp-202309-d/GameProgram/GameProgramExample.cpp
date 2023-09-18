#include "GameProgramExample.h"

void GameProgramExample::Start() override {
	int screenWidth = 1280;
	int screenHeight = 800;
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(screenWidth, screenHeight, "GameProgram");
	SetTargetFPS(60);

	Gui_Start();
}

void GameProgramExample::Update() override {
	BeginDrawing();
	ClearBackground(DARKGRAY);

	//Update Gui
	Gui_Update();

	EndDrawing();
}

void GameProgramExample::Terminate() override {
	Gui_Terminate();
	CloseWindow();
}

void GameProgramExample::Gui_Start() override {
	rlImGuiSetup(true);
}

void GameProgramExample::Gui_Update() override {
	// start ImGui Conent
	rlImGuiBegin();
	// show ImGui Content
	bool open = true;
	ImGui::ShowDemoWindow(&open);
	// end ImGui Content
	rlImGuiEnd();
}

void GameProgramExample::Gui_Terminate() override {
	rlImGuiShutdown();
}
