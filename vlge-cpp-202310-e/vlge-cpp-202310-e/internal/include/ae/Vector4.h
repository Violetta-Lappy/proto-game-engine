#pragma once

// TODO: add functionality

class Vector4 {
public:
	float x;
	float y;
	float z;
	float w;
public:
	Vector4(float arg_x, float arg_y, float arg_z, float arg_w) {
		x = arg_x;
		y = arg_y;
		z = arg_z;
		w = arg_w;
	}
public:
	void Normalize();
	void Inverse();
	void Abs();
};