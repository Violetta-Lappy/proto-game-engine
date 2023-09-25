#pragma once

#include "ResourceManager.h"
#include "AdMonetizationManager.h"
#include "AudioManager.h"
#include "GuiManager.h"
#include "LocalizationManager.h"
#include "TimeManager.h"

class GameProgramManager {
private:
	// TODO: input, time, gamemode, gamevalue, localization, camera
	ResourceManager m_resourceManager;
	GuiManager m_guiManager;
	AudioManager m_audioManager;
public:
	ResourceManager Get_ResourceManager() const {
		return m_resourceManager;
	}
	GuiManager Get_GuiManager() const {
		return m_guiManager;
	}
	AudioManager Get_AudioManager() const {
		return m_audioManager;
	}
};