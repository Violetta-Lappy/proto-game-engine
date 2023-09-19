#pragma once

//https://docs.godotengine.org/en/stable/classes/class_vector3.html
//https://github.com/Unity-Technologies/UnityCsReference/blob/master/Runtime/Export/Math/Vector3.cs

class Vector3 {
public:
	float x;
	float y;
	float z;
public:
	Vector3(float arg_x, float arg_y, float arg_z) {
		x = arg_x;
		y = arg_y;
		z = arg_z;
	}
public:
	static void Vector3 Normalize() {
		return Vector3(0, 0, 0);
	}
	static void Vector3 Clamp() {
		return Vector3(0, 0, 0);
	}
	static void Vector3 Clamp01() {
		return Vector3(0, 0, 0);
	}
public:
	static const Vector3 Zero() {
		return Vector3(0, 0, 0);
	}
	static const Vector3 One() {
		return Vector3(1, 1, 1);
	}

	// TODO: Proper Function
	static const Vector3 Up() {
		return Vector3(1, 1, 1);
	}
	static const Vector3 Down() {
		return Vector3(1, 1, 1);
	}
	static const Vector3 Back() {
		return Vector3(1, 1, 1);
	}
	static const Vector3 Forward() {
		return Vector3(1, 1, 1);
	}
	static const Vector3 Left() {
		return Vector3(1, 1, 1);
	}
	static const Vector3 Right() {
		return Vector3(1, 1, 1);
	}

	// TODO: Absolute Number
	static const Vector3 Abs() {
		return Vector3(1, 1, 1);
	}
	static const Vector3 Negative() {
		return Vector3(1, 1, 1);
	}
};