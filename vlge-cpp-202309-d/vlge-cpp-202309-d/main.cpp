#include "ProgramEngine/ENGINEProgram.h"

int main(int argc, char* argv[]) {
	
	ENGINEProgram program;

	program.Start();
	while (!WindowShouldClose()) {
		program.Update(0.0f, 0.0f);
	}
	program.Terminate();
	
	return KProgramExitCode::K_Success;
}