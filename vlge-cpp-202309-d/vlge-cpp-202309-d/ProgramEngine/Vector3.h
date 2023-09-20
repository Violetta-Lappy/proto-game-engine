#pragma once

//https://docs.godotengine.org/en/stable/classes/class_vector3.html
//https://github.com/Unity-Technologies/UnityCsReference/blob/master/Runtime/Export/Math/Vector3.cs

// TODO: add functionality

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
	void ToString() {
	}
public:
	// TODO: Absolute Number
	void Round() {
	}
	void Abs() {
	}
	void Negative() {
	}
	void Normalize() {		
	}
	void Clamp() {
	}
	void Clamp01() {		
	}
public:
	static const Vector3 Zero() {
		return Vector3(0, 0, 0);
	}
	static const Vector3 One() {
		return Vector3(1, 1, 1);
	}
	// TODO: Proper function
	static const Vector3 Infinity() {
		return Vector3(1, 1, 1);
	}
	// TODO: Proper function
	static const Vector3 NegativeInfinity() {
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
};