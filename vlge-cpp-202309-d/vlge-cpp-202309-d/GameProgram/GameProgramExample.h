#pragma once

#include "../GameProgram-Abstract/ABSGameProgram.h"

/// <summary>
/// Example of game.cpp should look like
/// </summary>
class GameProgramExample : public ABSGameProgram {
public:
	void Start() override;
	void Update() override;
	void Terminate() override;
	void Gui_Start() override;
	void Gui_Update() override;
	void Gui_Terminate() override;
};
