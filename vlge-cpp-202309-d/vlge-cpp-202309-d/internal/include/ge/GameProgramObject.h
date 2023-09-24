#pragma once

class GameProgramObject {
public:
	GameProgramObject();
	~GameProgramObject();
public:
	void Awake();
	void Start();
	void Update(float arg_dt, float arg_unscaledDt);
	void Terminate();
};