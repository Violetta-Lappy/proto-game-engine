#include "ProgramEngine/ENGINEProgram.h"
#include <rmlui/Core.h>
#include <rmlui/Debugger.h>

int main(int argc, char* argv[]) {
	
	//// Now we can initialize RmlUi.
	//Rml::Initialise();
	//// Create a context next.
	//Rml::Context* context = Rml::CreateContext("main", Rml::Vector2i(1280, 720));
	//if (!context) {
	//	Rml::Shutdown();
	//	return -1;
	//}
	//// If you want to use the debugger, initialize it now.
	//Rml::Debugger::Initialise(context);

	ENGINEProgram program;
	program.Start();
	while (!WindowShouldClose()) {
		program.Update(0.0f, 0.0f);
	}
	program.Terminate();
	
	return KProgramExitCode::K_Success;
}