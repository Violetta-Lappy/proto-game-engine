// NOTE: Declares global (extern) variables and screens functions
#include "raylib.h"
#include "screens.h"    

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Shared Variables Definition (global)
// NOTE: Those variables are shared between modules through screens.h
//----------------------------------------------------------------------------------
KGameScreen currentScreen = K_LogoSplashScreen;
Font font = { 0 };
Music music = { 0 };
Sound fxCoin = { 0 };

//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

// Required variables to manage screen transitions (fade-in, fade-out)
static float transAlpha = 0.0f;
static bool onTransition = false;
static bool transFadeOut = false;
static int transFromScreen = -1;
static KGameScreen transToScreen = K_Unknown;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void ChangeToScreen(int screen);     // Change to screen, no transition effect

static void TransitionToScreen(int screen); // Request transition to next screen
static void UpdateTransition(void);         // Update transition effect
static void DrawTransition(void);           // Draw transition effect (full-screen rectangle)

static void UpdateDrawFrame(void);          // Update and draw one frame

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void) {
	InitWindow(screenWidth, screenHeight, "RAYLIB - TEMPLATE - USING DEFAULT SETTING");

	// Initialize audio device
	InitAudioDevice();

	// Load global data (assets that must be available in all screens, i.e. font)
	font = LoadFont("resources/mecha.png");
	music = LoadMusicStream("resources/ambient.ogg");
	fxCoin = LoadSound("resources/coin.wav");

	SetMusicVolume(music, 1.0f);
	PlayMusicStream(music);

	// Setup and init first screen
	currentScreen = K_LogoSplashScreen;
	InitLogoScreen();

#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
	// Set our game to run at 60 frames-per-second
	SetTargetFPS(60);

	// Main game loop
	// Detect window close button or ESC key
	while (!WindowShouldClose()) {
		UpdateDrawFrame();
	}
#endif

	// De-Initialization
	//--------------------------------------------------------------------------------------
	// Unload current screen data before closing
	switch (currentScreen) {
		case K_LogoSplashScreen:
			{
				UnloadLogoScreen();
			}
			break;
		case K_TitleScreen:
			{
				UnloadTitleScreen();
			}
			break;
		case K_Gameplay:
			{
				UnloadGameplayScreen();
			}
			break;
		case K_End:
			{
				UnloadEndingScreen();
			}
			break;
		default: break;
	}

	// Unload global data loaded
	UnloadFont(font);
	UnloadMusicStream(music);
	UnloadSound(fxCoin);

	CloseAudioDevice();     // Close audio context

	CloseWindow();          // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

static void ChangeToScreen(KGameScreen screen) {
	// Unload current screen
	switch (currentScreen) {
		case K_LogoSplashScreen: UnloadLogoScreen(); break;
		case K_TitleScreen: UnloadTitleScreen(); break;
		case K_Gameplay: UnloadGameplayScreen(); break;
		case K_End: UnloadEndingScreen(); break;
		default: break;
	}

	// Init next screen
	switch (screen) {
		case K_LogoSplashScreen: InitLogoScreen(); break;
		case K_TitleScreen: InitTitleScreen(); break;
		case K_Gameplay: InitGameplayScreen(); break;
		case K_End: InitEndingScreen(); break;
		default: break;
	}

	currentScreen = screen;
}

static void TransitionToScreen(KGameScreen arg_gameScreenType) {
	onTransition = true;
	transFadeOut = false;
	transFromScreen = currentScreen;
	transToScreen = arg_gameScreenType;
	transAlpha = 0.0f;
}

static void UpdateTransition(void) {
	if (!transFadeOut) {
		transAlpha += 0.05f;

		// NOTE: Due to float internal representation, condition jumps on 1.0f instead of 1.05f
		// For that reason we compare against 1.01f, to avoid last frame loading stop
		if (transAlpha > 1.01f) {
			transAlpha = 1.0f;

			// Unload current screen
			switch (transFromScreen) {
				case K_LogoSplashScreen: UnloadLogoScreen(); break;
				case K_TitleScreen: UnloadTitleScreen(); break;
				case K_Option: UnloadOptionsScreen(); break;
				case K_Gameplay: UnloadGameplayScreen(); break;
				case K_End: UnloadEndingScreen(); break;
				default: break;
			}

			// Load next screen
			switch (transToScreen) {
				case K_LogoSplashScreen: InitLogoScreen(); break;
				case K_TitleScreen: InitTitleScreen(); break;
				case K_Gameplay: InitGameplayScreen(); break;
				case K_End: InitEndingScreen(); break;
				default: break;
			}

			currentScreen = transToScreen;

			// Activate fade out effect to next loaded screen
			transFadeOut = true;
		}
	}

	else {
		transAlpha -= 0.02f;

		if (transAlpha < -0.01f) {
			transAlpha = 0.0f;
			transFadeOut = false;
			onTransition = false;
			transFromScreen = -1;
			transToScreen = K_Unknown;
		}
	}
}

// Draw transition effect (full-screen rectangle)
static void DrawTransition(void) {
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
}

// Update and draw game frame
static void UpdateDrawFrame(void) {

	UpdateMusicStream(music);

	if (!onTransition) {
		switch (currentScreen) {
			case K_LogoSplashScreen:
				{
					UpdateLogoScreen();
					if (FinishLogoScreen()) {
						TransitionToScreen(K_TitleScreen);
					}
				}
				break;
			case K_TitleScreen:
				{
					UpdateTitleScreen();
					if (FinishTitleScreen() == 1) {
						TransitionToScreen(K_Option);
					}
					else if (FinishTitleScreen() == 2) {
						TransitionToScreen(K_Gameplay);
					}
				}
				break;
			case K_Option:
				{
					UpdateOptionsScreen();
					if (FinishOptionsScreen()) {
						TransitionToScreen(K_TitleScreen);
					}
				}
				break;
			case K_Gameplay:
				{
					UpdateGameplayScreen();
					if (FinishGameplayScreen() == 1) {
						TransitionToScreen(K_End);
					}
					//else if (FinishGameplayScreen() == 2) TransitionToScreen(TITLE);
				}
				break;
			case K_End:
				{
					UpdateEndingScreen();
					if (FinishEndingScreen() == 1) {
						TransitionToScreen(K_TitleScreen);
					}
				}
				break;
			default:
				break;
		}
	}
	else {
		UpdateTransition();
	}

	// Draw
	//----------------------------------------------------------------------------------
	BeginDrawing();

	ClearBackground(RAYWHITE);

	switch (currentScreen) {
		case K_LogoSplashScreen:
			{
				DrawLogoScreen();
			}
			break;
		case K_TitleScreen:
			{
				DrawTitleScreen();
			}
			break;
		case K_Option:
			{
				DrawOptionsScreen();
			}
			break;
		case K_Gameplay:
			{
				DrawGameplayScreen();
			}
			break;
		case K_End:
			{
				DrawEndingScreen();
			}
			break;
		default:
			break;
	}

	// Draw full screen rectangle in front of everything
	if (onTransition) {
		DrawTransition();
	}

	DrawFPS(10, 10);

	EndDrawing();
}
