#pragma once

#include <string>

enum KFullScreenMode {
	K_Window = 0,
	K_Borderless = 1,
	K_Fullscreen = 2,
};

class KFullScreenModeGuid {
public:
	const std::string K_Window = "406be012-0f9d-49a9-a613-9f5a17740f44";
	const std::string K_Borderless = "d09ba432-e6b9-40cc-b316-695bb0e95596";
	const std::string K_Fullscreen = "56171979-290d-467b-be51-cb35eea811c2";
};