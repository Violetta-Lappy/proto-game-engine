#include "ProgramEditor.h"

ProgramEditor::ProgramEditor() {
}

ProgramEditor::~ProgramEditor() {
}

void ProgramEditor::Start() {	
}

void ProgramEditor::Update(float arg_dt, float arg_unscaledDt) {	
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

	ShowOverlay(&open);
}

void ProgramEditor::Terminate() {	
}

void ProgramEditor::ShowOverlay(bool* p_open) {
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
		ImGui::Text("Violetta Lappy - Program Engine \n" "0.0.0 - D - 20230920");
		ImGui::Separator();
		ImGui::Text("FPS: | Vertex: | Audio: 0db");
		ImGui::Separator();
		ImGui::Text("right-click to change position");
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
