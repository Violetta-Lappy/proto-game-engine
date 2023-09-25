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
	const int Get_Width() {
		return i32_width;
	}
	const int Get_Height() {
		return i32_height;
	}
//--Portrait--
public:
	static const KScreenResolution K_600x800() {
		return KScreenResolution(600, 800);
	}
	static const KScreenResolution K_720x1280() {
		return KScreenResolution(720, 1280);
	}
//--Landscape--
public:
	static const KScreenResolution K_800x600() {
		return KScreenResolution(800, 600);
	}
	static const KScreenResolution K_1280x720() {
		return KScreenResolution(1280, 720);
	}
	static const KScreenResolution K_1920x1080() {
		return KScreenResolution(1920, 1080);
	}
};