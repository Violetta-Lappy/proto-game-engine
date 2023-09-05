using Raylib_cs;

namespace PROJECT_Program {
    public abstract class ABSAppProgramRaylib {
        public abstract void Start(AppProgramData arg_appProgramData);
        public abstract void Loop_DrawStart();
        public abstract void Loop_DrawLoop();
        public abstract void Loop_DrawTerminate();
        public abstract void Terminate();
    }

    public class AppProgramRaylib : ABSAppProgramRaylib {
        public override void Start(AppProgramData arg_appProgramData) {
            Raylib.InitWindow(arg_appProgramData.Get_ScreenWidth()
                , arg_appProgramData.Get_ScreenHeight()
                , arg_appProgramData.Get_ProgramName());
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