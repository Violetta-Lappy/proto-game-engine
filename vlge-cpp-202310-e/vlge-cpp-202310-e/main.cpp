// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

//https://github.com/ocornut/imgui/blob/master/examples/example_glfw_opengl3/main.cpp

//ViolettaLappy-ProgramEngine target for OpenGL (GLFW + GLAD), Vulkan, WebGPU

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <stdio.h>

// Will drag system OpenGL headers
#include <GLFW/glfw3.h> 

#include <ae/KExitCode.h>

// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

static void glfw_error_callback(int error, const char* description) {
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main(int, char**) {
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit()) {
		return KExitCode::K_Fail;
	}

	// Decide GL+GLSL versions
#if defined(__APPLE__)
	// GL 3.2 + GLSL 150
	const char* glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
	if (window == nullptr) {
		return KExitCode::K_Fail;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	// Load Fonts
	// - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.	
	//io.Fonts->AddFontDefault();
	//io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);	
	//ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
	//IM_ASSERT(font != nullptr);

	// Our state
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	// Main loop
#ifdef __EMSCRIPTEN__
	// For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
	// You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
	io.IniFilename = nullptr;
	EMSCRIPTEN_MAINLOOP_BEGIN
#else
	while (!glfwWindowShouldClose(window))
#endif
	{
		// Poll and handle events (inputs, window resize, etc.)		
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (show_demo_window) {
			ImGui::ShowDemoWindow(&show_demo_window);
		}

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
			ImGui::End();
		}

		{
			static bool h_isShowScene = false;
			static bool h_isShowGame = false;
			static bool h_isShowContentDrawer = false;
			static bool h_isShowAbout = false;
			static bool h_isShowOverlay = true;				

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
					if (ImGui::MenuItem("Scene", NULL, h_isShowScene)) {
						h_isShowScene = !h_isShowScene;
					}
					if (ImGui::MenuItem("Game", NULL, h_isShowGame)) {
						h_isShowGame = !h_isShowGame;
					}
					if (ImGui::MenuItem("Simple Overlay", NULL, h_isShowOverlay)) {
						h_isShowOverlay = !h_isShowOverlay;
					}
					ImGui::Separator();
					if (ImGui::MenuItem("Cmd Console", "(` | Ctrl+Shift+J | Ctrl+Shift+K)")) {
					}
					ImGui::Separator();
					if (ImGui::MenuItem("Text Editor")) {
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
					if (ImGui::MenuItem("About", NULL, h_isShowAbout)) {
						h_isShowAbout = !h_isShowAbout;
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
					if (ImGui::BeginMenu("Play[]")) {
						if (ImGui::Button("In Editor")) {
						}
						if (ImGui::Button("In Seperate Window")) {
						}
						ImGui::EndMenu();
					}
					if (ImGui::Button("Pause")) {
					}
					if (ImGui::Button("Next")) {
					}
					ImGui::EndMenuBar();
				}
				ImGui::End();
			}
			if (ImGui::BeginViewportSideBar("##MainStatusBar", viewport, ImGuiDir_Down, height, window_flags)) {
				if (ImGui::BeginMenuBar()) {
					if (ImGui::Button("Content Drawer")) {
						h_isShowContentDrawer = !h_isShowContentDrawer;
					}
					if (ImGui::Button("Cmd Console")) {
					}
					if (ImGui::Button("Compile")) {
					}
					ImGui::EndMenuBar();
				}
				ImGui::End();
			}
		}

		// 3. Show another simple window.
		if (show_another_window) {
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}
#ifdef __EMSCRIPTEN__
	EMSCRIPTEN_MAINLOOP_END;
#endif

	//--Terminate Cleanup--
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}