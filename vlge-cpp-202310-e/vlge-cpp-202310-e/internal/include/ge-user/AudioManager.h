#pragma once

class AudioManager {
private:
	int sz_audio_filepath;	
public:
	AudioManager(){ }
	~AudioManager(){ }
public:
	void PlayBgm();
	void PlaySfxGui();
	void PlaySfxGame();
	void PlayVoice();
};