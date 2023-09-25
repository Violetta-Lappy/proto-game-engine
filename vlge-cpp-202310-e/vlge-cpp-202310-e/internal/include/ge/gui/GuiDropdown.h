#pragma once

class GuiDropdown {
public:
	void OnPointerPress();
	void OnPointerHold();
	void OnPointerRelease();
	void OnPointerEnter();
	void OnPointerHover();
	void OnPointerExit();
public:
	void OnDropdownListChange();
	void OnDropdownItemSelect();
};