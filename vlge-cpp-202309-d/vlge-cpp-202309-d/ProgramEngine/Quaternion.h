#pragma once

//https://gitlab.com/libeigen/eigen/-/blob/master/Eigen/src/Geometry/Quaternion.h
//https://github.com/Unity-Technologies/Unity.Mathematics/blob/master/src/Unity.Mathematics/quaternion.cs

#include <string>
#include <fmt/format.h>

class Quaternion {
public:
	float x;
	float y;
	float z;
	float w;
public:
	Quaternion(float arg_x, float arg_y, float arg_z, float arg_w) {
		x = arg_x;
		y = arg_y;
		z = arg_z;
		w = arg_w;
	}
public:
	const std::string ToString() {
		return fmt::format("Quaterion: ({0}f, {1}f, {2}f, {3}f)", x, y, z, w);
	}
public:
	/// <summary>
	/// Normalizes the quaternion
	/// </summary>	
	const int Normalize() { }
	/// <summary>
	/// returns the quaternion describing the inverse rotation
	/// </summary>
	const int Inverse() { }
	/// <summary>
	/// returns the conjugated quaternion
	/// </summary>
	const int Conjugate() { }	
};