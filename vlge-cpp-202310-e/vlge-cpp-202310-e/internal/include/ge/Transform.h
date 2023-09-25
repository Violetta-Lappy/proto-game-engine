#pragma once

#include <ProgramEngine/Vector3.h>
#include <fmt/format.h>

class Transform {
public:
	Vector3 Position = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 Scale = Vector3(0.0f, 0.0f, 0.0f);
public:
	std::string ToString() {
		return fmt::format();
	}
};