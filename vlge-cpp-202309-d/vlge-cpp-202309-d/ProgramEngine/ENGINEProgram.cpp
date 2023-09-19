#include "ENGINEProgram.h"

void ENGINEProgram::Setup_Config() {
	bool canIniLoadSuccess = false;
	if (canIniLoadSuccess) {
		//setup if detect file
		// TODO: if detect programconfig.ini, set up
	}
	else {
		//default if not able to load file
		Get_Config().Set_ProgramName("Violetta Lappy - Game Example");
		Get_Config().Set_ScreenWidth(1280);
		Get_Config().Set_ScreenHeight(720);
		Get_Config().Set_TargetFps(KFpsTarget::K_60);
		Get_Config().Set_RefreshRate(KRefeshRate::K_30);
	}	
}

void ENGINEProgram::Start() {
}

void ENGINEProgram::Update(float arg_deltaTime, float arg_unscaledDeltaTime) {
}

void ENGINEProgram::Terminate() {
}

void ENGINEProgram::Gui_Start() {
}

void ENGINEProgram::Gui_Update(float arg_deltaTime, float arg_unscaledDeltaTime) {
}

void ENGINEProgram::Gui_Terminate() {
}
