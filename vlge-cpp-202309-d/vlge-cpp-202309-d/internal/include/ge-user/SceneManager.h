#pragma once

class SceneManager {
public:
	int sz_scene;
	int m_currentScene;
	int m_previousScene;
public:
	void Load(int arg_id);	
	void LoadAsync(int arg_id);	
	void LoadPrepare(int arg_id);
	void LoadAdd(int arg_id);
	void Unload(int arg_id);
};