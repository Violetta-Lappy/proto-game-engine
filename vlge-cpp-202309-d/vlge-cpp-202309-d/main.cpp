#include "raylib.h"
#include "raymath.h"

#include "imgui.h"
#include "rlImGui.h"

#include "fmt/format.h"

int main(int argc, char* argv[]) {	
	int screenWidth = 1280;
	int screenHeight = 800;

	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);	

	InitWindow(screenWidth, screenHeight, fmt::format("{0}, {1}, {2}", "helloworld", "fmt", "hoanglongplanner").c_str());
	SetTargetFPS(60);
	rlImGuiSetup(true);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		// start ImGui Conent
		rlImGuiBegin();

		// show ImGui Content
		bool open = true;
		ImGui::ShowDemoWindow(&open);

		// end ImGui Content
		rlImGuiEnd();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	rlImGuiShutdown();

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}