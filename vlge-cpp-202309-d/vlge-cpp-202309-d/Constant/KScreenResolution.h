#pragma once

class KScreenResolution {
private:
	int i32_width;
	int i32_height;
public:
	KScreenResolution(int arg_width, int arg_height) {
		i32_width = arg_width;
		i32_height = arg_height;
	}	
	int Get_Width() {
		return i32_width;
	}
	int Get_Height() {
		return i32_height;
	}
public:
	static KScreenResolution K_600x800_43_Portrait() {
		return KScreenResolution(600, 800);
	}
	static KScreenResolution K_800x600_43_Landscape() {
		return KScreenResolution(800, 600);
	}
	static KScreenResolution K_1920x1080_169_Landscape() {
		return KScreenResolution(1920, 1080);
	}
};