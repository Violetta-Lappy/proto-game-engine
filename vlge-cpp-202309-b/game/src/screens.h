#ifndef SCREENS_H
#define SCREENS_H

typedef enum KGameScreen {
	K_Unknown = -1,
	K_LogoSplashScreen = 0,
	K_TitleScreen,
	K_Option,
	K_Gameplay,
	K_End
} KGameScreen;

extern KGameScreen currentScreen;
extern Font font;
extern Music music;
extern Sound fxCoin;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

	//--Logo Screen--
	void InitLogoScreen(void);
	void UpdateLogoScreen(void);
	void DrawLogoScreen(void);
	void UnloadLogoScreen(void);
	int FinishLogoScreen(void);

	//--Title Screen--
	void InitTitleScreen(void);
	void UpdateTitleScreen(void);
	void DrawTitleScreen(void);
	void UnloadTitleScreen(void);
	int FinishTitleScreen(void);

	//--Options Screen--
	void InitOptionsScreen(void);
	void UpdateOptionsScreen(void);
	void DrawOptionsScreen(void);
	void UnloadOptionsScreen(void);
	int FinishOptionsScreen(void);

	//--Gameplay Screen--
	void InitGameplayScreen(void);
	void UpdateGameplayScreen(void);
	void DrawGameplayScreen(void);
	void UnloadGameplayScreen(void);
	int FinishGameplayScreen(void);


	//--Ending Screen--
	void InitEndingScreen(void);
	void UpdateEndingScreen(void);
	void DrawEndingScreen(void);
	void UnloadEndingScreen(void);
	int FinishEndingScreen(void);

#ifdef __cplusplus
}
#endif

#endif // SCREENS_H