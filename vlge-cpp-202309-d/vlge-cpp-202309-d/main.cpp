#include <iostream>
#include "raylib.h"
#include "Constant/KExitCode.h"
#include "Constant/KFpsTarget.h"

#include "imgui.h"
#include "rlImGui.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

const int K_ScreenWidth = 800;
const int K_ScreenHeight = 600;

int main(int argc, int* argv[]) {

	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(K_ScreenWidth, K_ScreenHeight, "raylib [core] example - basic window");

#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else

	// Set our game to run at 60 frames-per-second	
	SetTargetFPS(KFpsTarget::K_60());

	rlImGuiSetup(true);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		// Begin Imgui
		rlImGuiBegin();

		bool open = true;
		ImGui::ShowDemoWindow(&open);

		rlImGuiEnd();

		EndDrawing();
	}
#endif

	rlImGuiShutdown();

	// Close window and OpenGL context
	CloseWindow();

	// return success
	return KExitCode::K_Success();
}
