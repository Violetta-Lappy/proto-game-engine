#pragma once

// Similiar to Unity Transform Rect

class GuiTransform {
public:
	int anchorLocation;
	float width;
	float height;
	Vector3 Position = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 Scale = Vector3(0.0f, 0.0f, 0.0f);
public:
	std::string ToString() {
		return fmt::format();
	}
};