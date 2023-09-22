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

	ImGuiViewportP* viewport = (ImGuiViewportP*)(void*)ImGui::GetMainViewport();
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;
	float height = ImGui::GetFrameHeight();
	if (ImGui::BeginViewportSideBar("##SecondaryMenuBar", viewport, ImGuiDir_Up, height, window_flags)) {
		if (ImGui::BeginMenuBar()) {
			ImGui::Text("Secondary Menu Bar");

			if (ImGui::BeginMenu("Hand")) {
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Play[]")) {
				if (ImGui::MenuItem("In Editor")) {
				}
				if (ImGui::MenuItem("In Seperate Window")) {
				}
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Pause")) {
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Next")) {
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}
		ImGui::End();
	}
	if (ImGui::BeginViewportSideBar("##MainStatusBar", viewport, ImGuiDir_Down, height, window_flags)) {
		if (ImGui::BeginMenuBar()) {
			if (ImGui::Button("Content")) {
			}
			if (ImGui::Button("Cmd")) {
			}
			if (ImGui::Button("Compile")) {
			}
			ImGui::EndMenuBar();
		}
		ImGui::End();
	}

	// show ImGui Content
	bool open = true;
	ImGui::ShowDemoWindow(&open);

	ShowWorkspaceScene(&open);
	ShowWorkspaceGame(&open);

	ShowAboutWindow(&open);
	ShowOverlay(&open);
	ShowContentDrawer(&open);
}

void ProgramEditor::Terminate() {
	fmt::println("Violetta Lappy: ProgramEditor - Terminate Success [O]");
}

void ProgramEditor::ShowWorkspaceScene(bool* p_open) {
	if (ImGui::Begin("Scene", p_open)) {
	}
	ImGui::End();
}

void ProgramEditor::ShowWorkspaceGame(bool* p_open) {
	if (ImGui::Begin("Game", p_open)) {
	}
	ImGui::End();
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
		ImGui::Text("ViolettaLappyProgramEngine \n" "Release %s - %d - %s", VIOLETTALAPPY_RELEASE, VIOLETTALAPPY_YEARMONTH, VIOLETTALAPPY_VERSION);
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

void ProgramEditor::ShowAboutWindow(bool* p_open) {
	if (!ImGui::Begin("About", p_open, ImGuiWindowFlags_AlwaysAutoResize)) {
		ImGui::End();
		return;
	}

	if (ImGui::BeginPopupContextWindow()) {
		if (ImGui::MenuItem("Close")) {
		}
		ImGui::EndPopup();
	}

	ImGui::Text("ViolettaLappyProgramEngine - Release %s - %d - %s", VIOLETTALAPPY_RELEASE, VIOLETTALAPPY_YEARMONTH, VIOLETTALAPPY_VERSION);
	ImGui::Text("By Violetta & Lappy - hoanglongplanner");
	ImGui::Text("ViolettaLappyProgramEngine is licensed under the Apache2 License, see LICENSE for more information.");
	ImGui::Separator();

	ImGui::Text("Dear ImGui %s (%d)", IMGUI_VERSION, IMGUI_VERSION_NUM);
	ImGui::Text("By Omar Cornut and all Dear ImGui contributors.");
	ImGui::Text("Dear ImGui is licensed under the MIT License, see LICENSE for more information.");
	ImGui::Text("If your company uses this, please consider sponsoring the project!");

	static bool show_config_info = false;
	ImGui::Checkbox("Config/Build Information", &show_config_info);
	if (show_config_info) {
		ImGuiIO& io = ImGui::GetIO();
		ImGuiStyle& style = ImGui::GetStyle();

		bool copy_to_clipboard = ImGui::Button("Copy to clipboard");
		ImVec2 child_size = ImVec2(0, ImGui::GetTextLineHeightWithSpacing() * 18);
		ImGui::BeginChildFrame(ImGui::GetID("cfg_infos"), child_size, ImGuiWindowFlags_NoMove);
		if (copy_to_clipboard) {
			ImGui::LogToClipboard();
			ImGui::LogText("```\n"); // Back quotes will make text appears without formatting when pasting on GitHub
		}

		ImGui::Text("Dear ImGui %s (%d)", IMGUI_VERSION, IMGUI_VERSION_NUM);
		ImGui::Separator();
		ImGui::Text("sizeof(size_t): %d, sizeof(ImDrawIdx): %d, sizeof(ImDrawVert): %d", (int)sizeof(size_t), (int)sizeof(ImDrawIdx), (int)sizeof(ImDrawVert));
		ImGui::Text("define: __cplusplus=%d", (int)__cplusplus);
#ifdef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
		ImGui::Text("define: IMGUI_DISABLE_OBSOLETE_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_OBSOLETE_KEYIO
		ImGui::Text("define: IMGUI_DISABLE_OBSOLETE_KEYIO");
#endif
#ifdef IMGUI_DISABLE_WIN32_DEFAULT_CLIPBOARD_FUNCTIONS
		ImGui::Text("define: IMGUI_DISABLE_WIN32_DEFAULT_CLIPBOARD_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_WIN32_DEFAULT_IME_FUNCTIONS
		ImGui::Text("define: IMGUI_DISABLE_WIN32_DEFAULT_IME_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_WIN32_FUNCTIONS
		ImGui::Text("define: IMGUI_DISABLE_WIN32_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_DEFAULT_FORMAT_FUNCTIONS
		ImGui::Text("define: IMGUI_DISABLE_DEFAULT_FORMAT_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_DEFAULT_MATH_FUNCTIONS
		ImGui::Text("define: IMGUI_DISABLE_DEFAULT_MATH_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_DEFAULT_FILE_FUNCTIONS
		ImGui::Text("define: IMGUI_DISABLE_DEFAULT_FILE_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_FILE_FUNCTIONS
		ImGui::Text("define: IMGUI_DISABLE_FILE_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_DEFAULT_ALLOCATORS
		ImGui::Text("define: IMGUI_DISABLE_DEFAULT_ALLOCATORS");
#endif
#ifdef IMGUI_USE_BGRA_PACKED_COLOR
		ImGui::Text("define: IMGUI_USE_BGRA_PACKED_COLOR");
#endif
#ifdef _WIN32
		ImGui::Text("define: _WIN32");
#endif
#ifdef _WIN64
		ImGui::Text("define: _WIN64");
#endif
#ifdef __linux__
		ImGui::Text("define: __linux__");
#endif
#ifdef __APPLE__
		ImGui::Text("define: __APPLE__");
#endif
#ifdef _MSC_VER
		ImGui::Text("define: _MSC_VER=%d", _MSC_VER);
#endif
#ifdef _MSVC_LANG
		ImGui::Text("define: _MSVC_LANG=%d", (int)_MSVC_LANG);
#endif
#ifdef __MINGW32__
		ImGui::Text("define: __MINGW32__");
#endif
#ifdef __MINGW64__
		ImGui::Text("define: __MINGW64__");
#endif
#ifdef __GNUC__
		ImGui::Text("define: __GNUC__=%d", (int)__GNUC__);
#endif
#ifdef __clang_version__
		ImGui::Text("define: __clang_version__=%s", __clang_version__);
#endif
#ifdef __EMSCRIPTEN__
		ImGui::Text("define: __EMSCRIPTEN__");
#endif
#ifdef IMGUI_HAS_VIEWPORT
		ImGui::Text("define: IMGUI_HAS_VIEWPORT");
#endif
#ifdef IMGUI_HAS_DOCK
		ImGui::Text("define: IMGUI_HAS_DOCK");
#endif
		ImGui::Separator();
		ImGui::Text("io.BackendPlatformName: %s", io.BackendPlatformName ? io.BackendPlatformName : "NULL");
		ImGui::Text("io.BackendRendererName: %s", io.BackendRendererName ? io.BackendRendererName : "NULL");
		ImGui::Text("io.ConfigFlags: 0x%08X", io.ConfigFlags);
		if (io.ConfigFlags & ImGuiConfigFlags_NavEnableKeyboard)        ImGui::Text(" NavEnableKeyboard");
		if (io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad)         ImGui::Text(" NavEnableGamepad");
		if (io.ConfigFlags & ImGuiConfigFlags_NavEnableSetMousePos)     ImGui::Text(" NavEnableSetMousePos");
		if (io.ConfigFlags & ImGuiConfigFlags_NavNoCaptureKeyboard)     ImGui::Text(" NavNoCaptureKeyboard");
		if (io.ConfigFlags & ImGuiConfigFlags_NoMouse)                  ImGui::Text(" NoMouse");
		if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)      ImGui::Text(" NoMouseCursorChange");
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)            ImGui::Text(" DockingEnable");
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)          ImGui::Text(" ViewportsEnable");
		if (io.ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)  ImGui::Text(" DpiEnableScaleViewports");
		if (io.ConfigFlags & ImGuiConfigFlags_DpiEnableScaleFonts)      ImGui::Text(" DpiEnableScaleFonts");
		if (io.MouseDrawCursor)                                         ImGui::Text("io.MouseDrawCursor");
		if (io.ConfigViewportsNoAutoMerge)                              ImGui::Text("io.ConfigViewportsNoAutoMerge");
		if (io.ConfigViewportsNoTaskBarIcon)                            ImGui::Text("io.ConfigViewportsNoTaskBarIcon");
		if (io.ConfigViewportsNoDecoration)                             ImGui::Text("io.ConfigViewportsNoDecoration");
		if (io.ConfigViewportsNoDefaultParent)                          ImGui::Text("io.ConfigViewportsNoDefaultParent");
		if (io.ConfigDockingNoSplit)                                    ImGui::Text("io.ConfigDockingNoSplit");
		if (io.ConfigDockingWithShift)                                  ImGui::Text("io.ConfigDockingWithShift");
		if (io.ConfigDockingAlwaysTabBar)                               ImGui::Text("io.ConfigDockingAlwaysTabBar");
		if (io.ConfigDockingTransparentPayload)                         ImGui::Text("io.ConfigDockingTransparentPayload");
		if (io.ConfigMacOSXBehaviors)                                   ImGui::Text("io.ConfigMacOSXBehaviors");
		if (io.ConfigInputTextCursorBlink)                              ImGui::Text("io.ConfigInputTextCursorBlink");
		if (io.ConfigWindowsResizeFromEdges)                            ImGui::Text("io.ConfigWindowsResizeFromEdges");
		if (io.ConfigWindowsMoveFromTitleBarOnly)                       ImGui::Text("io.ConfigWindowsMoveFromTitleBarOnly");
		if (io.ConfigMemoryCompactTimer >= 0.0f)                        ImGui::Text("io.ConfigMemoryCompactTimer = %.1f", io.ConfigMemoryCompactTimer);
		ImGui::Text("io.BackendFlags: 0x%08X", io.BackendFlags);
		if (io.BackendFlags & ImGuiBackendFlags_HasGamepad)             ImGui::Text(" HasGamepad");
		if (io.BackendFlags & ImGuiBackendFlags_HasMouseCursors)        ImGui::Text(" HasMouseCursors");
		if (io.BackendFlags & ImGuiBackendFlags_HasSetMousePos)         ImGui::Text(" HasSetMousePos");
		if (io.BackendFlags & ImGuiBackendFlags_PlatformHasViewports)   ImGui::Text(" PlatformHasViewports");
		if (io.BackendFlags & ImGuiBackendFlags_HasMouseHoveredViewport)ImGui::Text(" HasMouseHoveredViewport");
		if (io.BackendFlags & ImGuiBackendFlags_RendererHasVtxOffset)   ImGui::Text(" RendererHasVtxOffset");
		if (io.BackendFlags & ImGuiBackendFlags_RendererHasViewports)   ImGui::Text(" RendererHasViewports");
		ImGui::Separator();
		ImGui::Text("io.Fonts: %d fonts, Flags: 0x%08X, TexSize: %d,%d", io.Fonts->Fonts.Size, io.Fonts->Flags, io.Fonts->TexWidth, io.Fonts->TexHeight);
		ImGui::Text("io.DisplaySize: %.2f,%.2f", io.DisplaySize.x, io.DisplaySize.y);
		ImGui::Text("io.DisplayFramebufferScale: %.2f,%.2f", io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
		ImGui::Separator();
		ImGui::Text("style.WindowPadding: %.2f,%.2f", style.WindowPadding.x, style.WindowPadding.y);
		ImGui::Text("style.WindowBorderSize: %.2f", style.WindowBorderSize);
		ImGui::Text("style.FramePadding: %.2f,%.2f", style.FramePadding.x, style.FramePadding.y);
		ImGui::Text("style.FrameRounding: %.2f", style.FrameRounding);
		ImGui::Text("style.FrameBorderSize: %.2f", style.FrameBorderSize);
		ImGui::Text("style.ItemSpacing: %.2f,%.2f", style.ItemSpacing.x, style.ItemSpacing.y);
		ImGui::Text("style.ItemInnerSpacing: %.2f,%.2f", style.ItemInnerSpacing.x, style.ItemInnerSpacing.y);

		if (copy_to_clipboard) {
			ImGui::LogText("\n```\n");
			ImGui::LogFinish();
		}
		ImGui::EndChildFrame();
	}
	ImGui::End();
}

void ProgramEditor::ShowContentDrawer(bool* p_open) {
	if (ImGui::Begin("Browser", p_open)) {
	}
	ImGui::End();
}
