#pragma once

// TODO: add functionality

class Vector4Int {
public:
	int x;
	int y;
	int z;
	int w;
public:
	Vector4Int(int arg_x, int arg_y, int arg_z, int arg_w) {
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