// vlge-cpp-202309-c.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "vlge-cpp-202309-c.h"

using namespace std;

//TODO: How to make this thing useful for main
struct KExitCode {
public:
	const int K_Success() {
		std::cout << "Program exit success." << std::endl;
		return 0;
	}
	const int K_Fail() {
		std::cout << "Program exit fail. Please Check." << std::endl;
		std::cout << "Export log." << std::endl;
		return 1;
	}
};

int main(int argc, char* argv[]) {
	const int K_ScreenWidth = 800;
	const int K_ScreenHeight = 600;

	return 0;
}
