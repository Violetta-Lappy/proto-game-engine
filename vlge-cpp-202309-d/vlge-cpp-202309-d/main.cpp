#include <raylib.h>
#include <engine/Program.h>

int main(int argc, char* argv[]) {		
	Program program;
	program.Awake();
	program.Start();
	while (!WindowShouldClose) {
		program.Update(0.0f, 0.0f);
	}	
	program.Terminate();	
	return 0;
}