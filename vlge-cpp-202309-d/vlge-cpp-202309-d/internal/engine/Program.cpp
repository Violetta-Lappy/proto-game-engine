#include "Program.h"

Program::Program() {		
}

Program::~Program() {		
}

void Program::SetupConfig() {
	bool canIniLoadSuccess = false;
	if (canIniLoadSuccess) {
		//setup if detect file
		// TODO: if detect programconfig.ini, set up
	}
	else {
		m_config.SetProgramName("ENGINEProgram");
		m_config.SetScreenWidth(1280);
		m_config.SetScreenHeight(720);
		m_config.SetTargetFps(KFpsTarget::K_60);
		m_config.SetRefreshRate(KRefeshRate::K_30);
	}	
}

void Program::Awake() {
	//Prepare config file
	SetupConfig();
	fmt::println(GetConfig().GetProgramName());
	fmt::println("Violetta Lappy: Setup Global Config - DONE [O]");	
	fmt::println("Violetta Lappy: Setup All Services with Global Config - DONE [O]");
	fmt::println("Violetta Lappy: Setup All Individual Services - DONE [O]");
}

void Program::Start() {
	//--SYSTEM DO NOT CHANGE UNLESS YOU KNOW WHAT TO DO--	
	//Setup raylib context
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(GetConfig().GetScreenWidth()
		, GetConfig().GetScreenHeight()
		, GetConfig().GetProgramName().c_str());
	SetTargetFPS(GetConfig().GetTargetFps());		
	rlImGuiSetup(true);
}

void Program::Update(float arg_dt, float arg_unscaledDt) {
	BeginDrawing();
	ClearBackground(DARKGRAY);

	rlImGuiBegin();

	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("ViolettaLappy")) {
			if (ImGui::MenuItem("Option")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Quit", "Alt+F4")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("New", "Ctrl+N")) {
			}
			if (ImGui::MenuItem("New from Template")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Open", "Ctrl+O")) {
			}
			if (ImGui::MenuItem("Open Recent")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Recover Last Session")) {
			}
			if (ImGui::MenuItem("Recover Autosave")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Save", "Ctrl+S")) {
			}
			if (ImGui::MenuItem("Save As", "Ctrl+Shift+S")) {
			}
			if (ImGui::MenuItem("Save New Version", "Ctrl+Alt+S")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Close Document")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit")) {
			if (ImGui::MenuItem("Undo", "CTRL+Z")) {
			}
			if (ImGui::MenuItem("Redo", "CTRL+Y")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Cut", "CTRL+X")) {
			}
			if (ImGui::MenuItem("Copy", "CTRL+C")) {
			}
			if (ImGui::MenuItem("Paste", "CTRL+V")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View")) {
			if (ImGui::MenuItem("Text Editor")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Simple Overlay")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Terminal Console", "(` | Ctrl+Shift+J)")) {
			}
			if (ImGui::MenuItem("Imgui Console", "(` | Ctrl+Shift+K)")) {
			}
			if (ImGui::MenuItem("Rmlui Console", "(` | Ctrl+Shift+L)")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Option")) {
			if (ImGui::MenuItem("Program Config")) {
			}
			if (ImGui::MenuItem("Window")) {
			}
			if (ImGui::MenuItem("Theme Customization")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Help")) {
			if (ImGui::MenuItem("Manual")) {
			}
			if (ImGui::MenuItem("About")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("3rdParty")) {
			if (ImGui::MenuItem("Text Editor")) {
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	// show ImGui Content
	bool open = true;
	ImGui::ShowDemoWindow(&open);	

	rlImGuiEnd();

	EndDrawing();
}

void Program::Terminate() {
	rlImGuiShutdown();
	CloseWindow();
}
