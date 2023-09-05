using ImGuiNET;
using rlImGui_cs;

namespace PROJECT_Program {
	public abstract class ABSAppProgramDearImgui {
		public abstract void Start();
		public abstract void Loop();
		public abstract void Terminate();
	}

	public class AppProgramDearImgui : ABSAppProgramDearImgui {
		public override void Start() {
			rlImGui.Setup(true);
		}
		public override void Loop() {
			rlImGui.Begin();
			ImGui.ShowDemoWindow();
			rlImGui.End();
		}
		public override void Terminate() {
			rlImGui.Shutdown();
		}
	}
}