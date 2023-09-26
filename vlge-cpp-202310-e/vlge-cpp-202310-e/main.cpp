// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

//https://github.com/ocornut/imgui/blob/master/examples/example_glfw_opengl3/main.cpp

//ViolettaLappy-ProgramEngine target for OpenGL (GLFW + GLAD), Vulkan, WebGPU
//DO NOT TARGET FOR ANDROID & IOS

#include <stdio.h>

#include <fmt/format.h>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <GLFW/glfw3.h> 

#include <engine/ProgramConfig.h>
#include <engine/ProgramEditor.h>
#include <ae/KExitCode.h>

#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

static void glfw_error_callback(int error, const char* description) {
	//fprintf(stderr, "GLFW Error %d: %s\n", error, description);
	fmt::println("GLFW Error {0}: {1}", error, description);
}

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void draw(GLFWwindow* window);

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

	//while resize, render screen to not look sloppy
	//NOTE: NOT IMPLEMENTED FOR PERFORMANCE REASON
	//- INCREASE PROCESS MEMORY 200+mb
	//- FIX BLACK LINE, but not implemented as reason stated
	//draw(window);
}

void draw(GLFWwindow* window) {
	//--render--
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//--glfw: swap buffers--
	glfwSwapBuffers(window);
}

int main(int, char**) {
	//--glfw: setup--
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit()) {
		return KExitCode::K_Fail;
	}
	// Decide what GL+GLSL versions
#if defined(__APPLE__)
	// GL 3.2 + GLSL 150
	//https://en.wikipedia.org/wiki/OpenGL_Shading_Language
	const char* glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	// 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  
	// 3.0+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            
#else
	// GL 4.6 + GLSL 460
	//https://en.wikipedia.org/wiki/OpenGL_Shading_Language
	const char* glsl_version = "#version 460";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);	
	// 3.2+ only
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  
	// 3.0+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            
#endif
	//glfw: create window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
	if (window == nullptr) {
		return KExitCode::K_Fail;
	}
	//glfw: set window size limit (min, max)
	glfwSetWindowSizeLimits(
		window,
		static_cast<int>(800),
		static_cast<int>(600),
		static_cast<int>(1280),
		static_cast<int>(720)
	);
	glfwMakeContextCurrent(window);
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//Enable Vsync
	glfwSwapInterval(1); 

	//--imgui: setup--
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); 
	(void)io;
	// Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     
	// Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      
	//imgui: set style
	ImGui::StyleColorsDark();
	ImGui::GetStyle().FrameRounding = 2.0f;
	ImGui::GetStyle().GrabRounding = 2.0f;
	//imgui: set platform & renderer
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	//--imgui: Load Fonts--
	//If no fonts are loaded, dear imgui will use the default font. 
	//You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.	
	io.Fonts->AddFontDefault();	
	ImFont* font = io.Fonts->AddFontFromFileTTF("font/IBMPlexSans-Regular.ttf", 16.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
	IM_ASSERT(font != nullptr);

	//imgui: window setup
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	//--program: variable--
	ProgramEditor editor;
	
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

		//--imgui: stuff--
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		
		//--imgui: small window--
		{
			static float f = 0.0f;
			static int counter = 0;

			// Create a window called "Hello, world!" and append into it.
			ImGui::Begin("Hello, world!");

			// Display some text (you can use a format strings too)
			ImGui::Text("This is some useful text.");               
			// Edit bools storing our window open/close state
			ImGui::Checkbox("Demo Window", &show_demo_window);     
			ImGui::Checkbox("Another Window", &show_another_window);

			// Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            
			// Edit 3 floats representing a color
			ImGui::ColorEdit3("clear color", (float*)&clear_color); 

			if (ImGui::Button("Button")) {
				counter++;
			}				
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
			ImGui::End();
		}

		//ProgramEditor
		editor.Update(0.0f, 0.0f);

		//--imgui: rendering--
		ImGui::Render();
		int display_w, display_h;
		//based on glfw window currently assigned, get referenced window width and height value
		glfwGetFramebufferSize(window, &display_w, &display_h);
		//fmt::println("GLFW: Width {0} Height {1}", display_w, display_h);

		//--glfw: render--
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}
#ifdef __EMSCRIPTEN__
	EMSCRIPTEN_MAINLOOP_END;
#endif

	//--program: Terminate Cleanup--
	//imgui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	//glfw
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}