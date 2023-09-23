/*
Copyright 2023 ViolettaLappy hoanglongplanner

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <engine/Program.h>

int main(int argc, char* argv[]) {
	Program program;
	program.Start();

	// Define the camera to look into our 3d world
	Camera3D camera = { 0 };
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

	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	while (!WindowShouldClose()) {
		program.Update(0.0f, 0.0f);

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
	program.Terminate();
	return 0;
}