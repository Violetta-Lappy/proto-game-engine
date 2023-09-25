#pragma once

//Inspire by TextMeshPro from Unity
//With all string format
//Weird HTML tags too

class GuiText {
public:
	int fontType;
	int fontSize;
public:
	void SetFont();
	void SetFontSize();
public:
	void OnPointerPress();
	void OnPointerHold();
	void OnPointerRelease();
	void OnPointerEnter();
	void OnPointerHover();
	void OnPointerExit();
};