#pragma once

// Similiar to Input in Unity and SDL

class Input {
public:
	//--Axis--
	bool GetAxis();
	bool GetAxisDown();
	bool GetAxisUp();
	//--Keyboard--
	bool GetKey();
	bool GetKeyDown();
	bool GetKeyUp();
	//--Mouse--
	bool GetMouse();
	bool GetMouseDown();
	bool GetMouseUp();
	//--Gamepad--
	bool GetGamepad();
	bool GetGamepadDown();
	bool GetGamepadUp();
	//--TouchDevice--
	bool GetTouch();
	//--Context-- this is custom class that like Unreal and Unity, user-oriented input setup
	bool GetContext();
	bool GetContextDown();
	bool GetContextUp();
};