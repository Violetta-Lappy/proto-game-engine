#include "GameProgram/GameProgramExample.h"

int main(int argc, char* argv[]) {
	GameProgramExample game;
	game.Start();	
	while (!WindowShouldClose()) {
		game.Update();
	}
	game.Terminate();

	return 0;
}