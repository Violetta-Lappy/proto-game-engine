namespace PROJECT_Program {
	public abstract class ABSPROGRAMProgramMain {
		//PRIVATE: Variable
		ProgramSetting m_programSetting = new ProgramSetting();
		PROGRAMRaylib m_raylib = new PROGRAMRaylib();
		PROGRAMDearImgui m_imgui = new PROGRAMDearImgui();

		//PUBLIC: Function
		public ProgramSetting Get_ProgramSetting() { return m_programSetting; }
		public PROGRAMRaylib Get_Raylib() { return m_raylib; }
		public PROGRAMDearImgui Get_DearImgui() { return m_imgui; }
		public abstract void Start();
		public abstract void Loop();
		public abstract void Terminate();
	}

	public class PROGRAMProgramMain : ABSPROGRAMProgramMain {
		public override void Start() {
			Get_ProgramSetting()
				.Set_ProgramName("PROGRAM - RAYLIB SUCCESSFUL")
				.Set_ScreenWidth(800)
				.Set_ScreenHeight(600);

			//Get_Raylib().Start(new ProgramSetting());
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