#include "ENGINEProgram.h"

void ENGINEProgram::SetupConfig() {
	bool canIniLoadSuccess = false;
	if (canIniLoadSuccess) {
		//setup if detect file
		// TODO: if detect programconfig.ini, set up
	}
	else {
		m_config.Set_ProgramName("ENGINEProgram");
		m_config.Set_ScreenWidth(1280);
		m_config.Set_ScreenHeight(720);
		m_config.Set_TargetFps(KFpsTarget::K_60);
		m_config.Set_RefreshRate(KRefeshRate::K_30);
	}	

	fmt::println(GetConfig().Get_ProgramName());
}

void ENGINEProgram::Start() {
	SetupConfig();
	
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

	InitWindow(GetConfig().Get_ScreenWidth()
		, GetConfig().Get_ScreenHeight()
		, GetConfig().Get_ProgramName().c_str());

	SetTargetFPS(GetConfig().Get_TargetFps());

	GuiStart();
}

void ENGINEProgram::Update(float arg_dt, float arg_unscaledDt) {
	BeginDrawing();
	ClearBackground(DARKGRAY);

	//Update Gui
	GuiUpdate(arg_dt, arg_unscaledDt);

	EndDrawing();
}

void ENGINEProgram::Terminate() {
	GuiTerminate();
	CloseWindow();
}

void ENGINEProgram::GuiStart() {
	rlImGuiSetup(true);
}

void ENGINEProgram::GuiUpdate(float arg_dt, float arg_unscaledDt) {	
	rlImGuiBegin();
	
	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("ViolettaLappy")) {
			if (ImGui::MenuItem("Option")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Exit")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("New")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Open (Ctrl+O)")) {
			}
			if (ImGui::MenuItem("Open Recent")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Save (Ctrl+S)")) {
			}
			if (ImGui::MenuItem("Save As (Ctrl+Shift+S)")) {
			}
			if (ImGui::MenuItem("Save New Version (Ctrl+Alt+S)")) {
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Close Document")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit")) {			
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View")) {
			if (ImGui::MenuItem("Simple Overlay")) {
			}
			if (ImGui::MenuItem("Debug Console (` or Ctrl+Shift+K)")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Option")) {
			if (ImGui::MenuItem("Window")) {
			}
			if (ImGui::MenuItem("Theme Customization")) {
			}
			ImGui::EndMenu();
		}		
		if (ImGui::BeginMenu("Help")) {
			if (ImGui::MenuItem("Credit")) {
			}
			if (ImGui::MenuItem("About")) {
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}	

	// show ImGui Content
	bool open = true;
	ImGui::ShowDemoWindow(&open);

	Gui_ShowOverlay(&open);

	rlImGuiEnd();
}

void ENGINEProgram::GuiTerminate() {
	rlImGuiShutdown();
}

void ENGINEProgram::Gui_ShowOverlay(bool* p_open) {
	static int location = 3;
	ImGuiIO& io = ImGui::GetIO();
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
	if (location >= 0) {
		const float PAD = 10.0f;
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		// Use work area to avoid menu-bar/task-bar, if any!
		ImVec2 work_pos = viewport->WorkPos; 
		ImVec2 work_size = viewport->WorkSize;
		ImVec2 window_pos, window_pos_pivot;
		window_pos.x = (location & 1) ? (work_pos.x + work_size.x - PAD) : (work_pos.x + PAD);
		window_pos.y = (location & 2) ? (work_pos.y + work_size.y - PAD) : (work_pos.y + PAD);
		window_pos_pivot.x = (location & 1) ? 1.0f : 0.0f;
		window_pos_pivot.y = (location & 2) ? 1.0f : 0.0f;
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
		ImGui::SetNextWindowViewport(viewport->ID);
		window_flags |= ImGuiWindowFlags_NoMove;
	}
	// Center window
	else if (location == -2) {		
		ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
		window_flags |= ImGuiWindowFlags_NoMove;
	}
	// Transparent background
	ImGui::SetNextWindowBgAlpha(0.35f); 
	if (ImGui::Begin("Example: Simple overlay", p_open, window_flags)) {		
		ImGui::Text("Simple overlay\n" "(right-click to change position)");
		ImGui::Separator();
		if (ImGui::IsMousePosValid())
			ImGui::Text("Mouse Position: (%.1f,%.1f)", io.MousePos.x, io.MousePos.y);
		else
			ImGui::Text("Mouse Position: <invalid>");
		if (ImGui::BeginPopupContextWindow()) {
			if (ImGui::MenuItem("Custom", NULL, location == -1)) location = -1;
			if (ImGui::MenuItem("Center", NULL, location == -2)) location = -2;
			if (ImGui::MenuItem("Top-left", NULL, location == 0)) location = 0;
			if (ImGui::MenuItem("Top-right", NULL, location == 1)) location = 1;
			if (ImGui::MenuItem("Bottom-left", NULL, location == 2)) location = 2;
			if (ImGui::MenuItem("Bottom-right", NULL, location == 3)) location = 3;
			if (p_open && ImGui::MenuItem("Close")) *p_open = false;
			ImGui::EndPopup();
		}
	}
	ImGui::End();
}
