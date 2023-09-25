#include "ProgramRender.h"

ProgramRender::ProgramRender() {
}

ProgramRender::~ProgramRender() {
}

void ProgramRender::Start() {    	
	// Camera position
	camera.position = { 10.0f, 10.0f, 10.0f };
	// Camera looking at point
	camera.target = { 0.0f, 0.0f, 0.0f };
	// Camera up vector (rotation towards target)
	camera.up = { 0.0f, 1.0f, 0.0f };
	// Camera field-of-view Y
	camera.fovy = 45.0f;
	// Camera projection type
	camera.projection = CAMERA_PERSPECTIVE;	
}

void ProgramRender::Update(float arg_dt, float arg_unscaledDt) {    
	ClearBackground(WHITE);

	UpdateCamera(&camera, CAMERA_FREE);

	if (IsKeyDown('Z')) {
		camera.target = { 0.0f, 0.0f, 0.0f };
	}

	BeginMode3D(camera);

	DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
	DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

	DrawGrid(10, 1.0f);

	EndMode3D();

	DrawRectangle(10, 10, 320, 133, Fade(SKYBLUE, 0.5f));
	DrawRectangleLines(10, 10, 320, 133, BLUE);

	DrawText("Free camera default controls:", 20, 20, 10, BLACK);
	DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
	DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
	DrawText("- Alt + Mouse Wheel Pressed to Rotate", 40, 80, 10, DARKGRAY);
	//DrawText("- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", 40, 100, 10, DARKGRAY);
	DrawText("- Z to zoom to (0, 0, 0)", 40, 120, 10, DARKGRAY);
}

void ProgramRender::Terminate() {
}
