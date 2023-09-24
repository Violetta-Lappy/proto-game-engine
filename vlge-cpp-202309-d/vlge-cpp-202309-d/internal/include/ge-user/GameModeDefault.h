#pragma once

//All game enviroment stuff will be in here

class GameModeDefault {
public:
	//Add all game setup variable
	int enemyNumber;
public:
	//--Game Rule--
	void GameRule_Setup();	
	void GameRule_Resolve();
	//--Game State--
	void GameState_Restart();
	void GameState_Start();
	void GameState_Update();
	void GameState_End();
};