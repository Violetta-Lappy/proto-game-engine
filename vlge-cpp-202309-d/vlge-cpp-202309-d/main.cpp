#include <iostream>
#include "raylib.h"
#include "Constant/KExitCode.h"

#include "AppProgram/AppProgram.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

const int K_ScreenWidth = 800;
const int K_ScreenHeight = 600;

class KFpsTarget {
public:
	static const int K_144 = 144;
	static const int K_60 = 60;
	static const int K_30 = 30;
};

int main(int argc, int* argv[]) {
		
	InitWindow(K_ScreenWidth, K_ScreenHeight, "raylib [core] example - basic window");

#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else

	// Set our game to run at 60 frames-per-second	
	SetTargetFPS(KFpsTarget::K_60);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}
#endif

	// Close window and OpenGL context
	CloseWindow();	

	// return success
	return KExitCode::K_Success();
}
