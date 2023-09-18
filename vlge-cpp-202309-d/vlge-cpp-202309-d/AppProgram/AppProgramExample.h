#pragma once

#include "../Abstract/ABSAppProgram.h"

class AppProgramExample : ABSAppProgram {
public:
	AppProgramExample();
	~AppProgramExample();
	void Start() override;
	void Loop() override;
	void Terminate() override;
};