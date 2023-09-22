#pragma once

#include <ge/Scene.h>

class Scene_TitleScreen : Scene {
	// Inherited via Scene
	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update(float arg_dt, float arg_unscaledDt) override;
	virtual void End() override;	
};