#pragma once

//https://github.com/thezbyg/gpick/blob/master/source/Color.h
//https://github.com/Unity-Technologies/UnityCsReference/blob/master/Runtime/Export/Math/Color.cs

#include <fmt/format.h>

class Color {
public:
	float r;
	float g;
	float b;
	float a;
public:
	Color(float arg_r, float arg_g, float arg_b, float arg_a) {
		r = arg_r;
		g = arg_g;
		b = arg_b;
		a = arg_a;
	}
public:
	std::string ToString() {
		return fmt::format("Color RGBA: {0} {1} {2} {3}", r, g, b, a);
	}
public:
	static Color Red {  
		return Color(1.0f, 0.0f, 0.0f, 1.0f); 
	}
	static Color Green {
		return Color(0.0f, 1.0f, 0.0f, 1.0f); 
	}
	static Color Blue {
		return Color(0.0f, 0.0f, 1.0f, 1.0f);
	}
	static Color White {
		return Color(1.0f, 1.0f, 1.0f, 1.0f);
	}
	static Color Black { 
		return Color(0.0f, 0.0f, 0.0f, 1.0f); 
	}
	static Color Yellow { 
		return Color(1.0f, 235.0f / 255.0f, 4.0f / 255.0f, 1.0f); 
	}
	static Color Cyan { 
		return Color(0.0f, 1.0f, 1.0f, 1.0f); 
	}
	static Color Magenta { 
		return Color(1.0f, 0.0f, 1.0f, 1.0f); 
	}
	static Color Gray { 
		return Color(0.5f, 0.5f, 0.5f, 1.0f); 
	}
	static Color Grey { 
		return Color(0.5f, 0.5f, 0.5f, 1.0f); 
	}
	static Color Clear { 
		return Color(0.0f, 0.0f, 0.0f, 0.0f); 
	}
};