using Raylib_cs;
using rlImGui_cs;
using ImGuiNET;
using VLAppProgram;

class Program {
    public static void Main() {
        AppProgramExample appProgram = new AppProgramExample();
        appProgram.Start();
        while (Raylib.WindowShouldClose() == false) {
            appProgram.Loop();
        }
        appProgram.Terminate();
    }
}