#pragma once

class Vector3Int {
public:
	int x;
	int y;
	int z;
public:
	Vector3Int(int arg_x, int arg_y, int arg_z) {
		x = arg_x;
		y = arg_y;
		z = arg_z;
	}
public:
	static void ToString() {
	}
public:
	static void Normalize() {
	}
	static void Clamp() {
	}
	static void Clamp01() {
	}
public:
	static const Vector3Int Zero() {
		return Vector3Int(0, 0, 0);
	}
	static const Vector3Int One() {
		return Vector3Int(1, 1, 1);
	}
};