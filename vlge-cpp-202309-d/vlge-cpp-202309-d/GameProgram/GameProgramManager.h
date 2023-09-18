#pragma once

#include "../GameProgram/GPGuiManager.h"
#include "../GameProgram/GPAudioManager.h"

class GameProgramManager {
private:
	// TODO: input, time, gamemode, gamevalue, localization, camera
	GPGuiManager m_guiManager;
	GPAudioManager m_audioManager;
public:
	GPGuiManager Get_GuiManager() {
		return m_guiManager;
	}
	GPAudioManager Get_AudioManager() {
		return m_audioManager;
	}
};