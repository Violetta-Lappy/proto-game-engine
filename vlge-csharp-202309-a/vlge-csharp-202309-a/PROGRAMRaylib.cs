using Raylib_cs;

namespace PROJECT_Program {
	public abstract class ABSPROGRAMRaylib {		
		public abstract void Start(ProgramSetting arg_programSetting);
		public abstract void Loop_DrawStart();
		public abstract void Loop_DrawLoop();
		public abstract void Loop_DrawTerminate();
		public abstract void Terminate();
	}

	public class PROGRAMRaylib : ABSPROGRAMRaylib {		
		public override void Start(ProgramSetting arg_programSetting) {
			Raylib.InitWindow(arg_programSetting.Get_ScreenWidth()
				, arg_programSetting.Get_ScreenHeight()
				, arg_programSetting.Get_ProgramName());
		}
		public override void Loop_DrawStart() => Raylib.BeginDrawing();
		public override void Loop_DrawLoop() {
			Raylib.ClearBackground(Color.WHITE);
			Raylib.DrawText("Hello World", 12, 12, 20, Color.BLACK);
		}
		public override void Loop_DrawTerminate() => Raylib.EndDrawing();
		public override void Terminate() => Raylib.CloseWindow();
	}
}