#pragma once

class GuiPage {
public:
	virtual void Start() = 0;
	virtual void Update(float arg_dt, float arg_unscaledDt) = 0;
	virtual void End() = 0;
};