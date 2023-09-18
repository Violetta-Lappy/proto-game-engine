#pragma once

#include "raylib.h"

class ABSAppProgram {
public:
	virtual void Start();
	virtual void Loop();
	virtual void Terminate();	
};