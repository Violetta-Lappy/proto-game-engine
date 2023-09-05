using Raylib_cs;
using rlImGui_cs;
using ImGuiNET;
using PROJECT_Program;

class Program {
	public static void Main() {
		PROGRAMProgramMain h_program = new PROGRAMProgramMain();
		h_program.Start();
		while (Raylib.WindowShouldClose() == false) {
			h_program.Loop();
		}
		h_program.Terminate();
	}
}