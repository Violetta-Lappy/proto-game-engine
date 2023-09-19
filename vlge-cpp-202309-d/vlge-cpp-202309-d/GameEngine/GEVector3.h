#pragma once

//https://docs.godotengine.org/en/stable/classes/class_vector3.html

struct GEVector3 {
	float x;
	float y;
	float z;

	GEVector3(float arg_x, float arg_y, float arg_z) {
		x = arg_x;
		y = arg_y;
		z = arg_z;
	}

	static const GEVector3 Zero() {
		return GEVector3(0, 0, 0);
	}
	static const GEVector3 One() {
		return GEVector3(1, 1, 1);
	}

	// TODO: Proper Function
	static const GEVector3 Up() {
		return GEVector3(1, 1, 1);
	}
	static const GEVector3 Down() {
		return GEVector3(1, 1, 1);
	}
	static const GEVector3 Back() {
		return GEVector3(1, 1, 1);
	}
	static const GEVector3 Forward() {
		return GEVector3(1, 1, 1);
	}
	static const GEVector3 Left() {
		return GEVector3(1, 1, 1);
	}
	static const GEVector3 Right() {
		return GEVector3(1, 1, 1);
	}

	// TODO: Absolute Number
	static const GEVector3 Abs() {
		return GEVector3(1, 1, 1);
	}
	static const GEVector3 Negative() {
		return GEVector3(1, 1, 1);
	}
};