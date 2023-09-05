namespace PROJECT_Program {
	public abstract class ABSAppProgramMain {
		//PRIVATE: Variable		
		AppProgramRaylib m_raylib = new AppProgramRaylib();
		AppProgramDearImgui m_imgui = new AppProgramDearImgui();

		//PUBLIC: Function
		public abstract AppProgramData Get_ProgramSetting();		
		public AppProgramRaylib Get_Raylib() { return m_raylib; }
		public AppProgramDearImgui Get_DearImgui() { return m_imgui; }
		public abstract void Start();
		public abstract void Loop();
		public abstract void Terminate();
	}

	public class AppProgramMain : ABSAppProgramMain {
        public override AppProgramData Get_ProgramSetting() {
            return new AppProgramData()
                .Set_ProgramName("PROGRAM - RAYLIB SUCCESSFUL - HAS BEEN INITIALIZE")
                .Set_ScreenWidth(800)
                .Set_ScreenHeight(600);
        }

        public override void Start() {									
			Get_Raylib().Start(Get_ProgramSetting());
			Get_DearImgui().Start();
		}
		public override void Loop() {
			Get_Raylib().Loop_DrawStart();
			Get_Raylib().Loop_DrawLoop();

			//DearImgui must be place
			//between Raylib.Loop_DrawStart and Raylib.Loop_DrawTerminate
			//or it won't work at all
			//not sure why this is the case
			Get_DearImgui().Loop();

			Get_Raylib().Loop_DrawTerminate();
		}
		public override void Terminate() {
			Get_Raylib().Terminate();
			Get_DearImgui().Terminate();
		}        
    }
}