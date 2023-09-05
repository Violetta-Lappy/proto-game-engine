using ImGuiNET;
using rlImGui_cs;

namespace PROJECT_Program {
	public abstract class ABSPROGRAMDearImgui {
		public abstract void Start();
		public abstract void Loop();
		public abstract void Terminate();
	}

	public class PROGRAMDearImgui : ABSPROGRAMDearImgui {
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