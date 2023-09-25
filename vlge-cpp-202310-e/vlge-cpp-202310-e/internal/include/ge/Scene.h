#pragma once

class Scene {
public:
	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void Update(float arg_dt, float arg_unscaledDt) = 0;
	virtual void End() = 0;
};