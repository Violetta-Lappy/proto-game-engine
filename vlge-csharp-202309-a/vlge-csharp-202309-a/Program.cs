using Raylib_cs;
using rlImGui_cs;
using ImGuiNET;
using PROJECT_Program;

class Program {
	public static void Main() {
		AppProgramMain h_program = new AppProgramMain();
		h_program.Start();
		while (Raylib.WindowShouldClose() == false) {
			h_program.Loop();
		}
		h_program.Terminate();
	}
}