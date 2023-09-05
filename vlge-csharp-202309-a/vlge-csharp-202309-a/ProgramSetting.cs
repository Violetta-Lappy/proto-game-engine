namespace PROJECT_Program {
	public abstract class ABSProgramSetting {
		//PRIVATE: Variable
		private string str_programName = "PROGRAM - TEMPLATE - PLEASE SETUP CORRECTLY";
		private int i32_screenWidth = 800;
		private int i32_screenHeight = 600;

		//PUBLIC: Function, Builder Design Pattern
		public string Get_ProgramName() { return str_programName; }
		public int Get_ScreenWidth() { return i32_screenWidth; }
		public int Get_ScreenHeight() { return i32_screenHeight; }
		public ABSProgramSetting Set_ProgramName(string arg_name) {
			str_programName = arg_name;
			return this;
		}
		public ABSProgramSetting Set_ScreenWidth(int arg_value) {
			i32_screenWidth = arg_value;
			return this;
		}
		public ABSProgramSetting Set_ScreenHeight(int arg_value) {
			i32_screenHeight = arg_value;
			return this;
		}
	}

	public class ProgramSetting : ABSProgramSetting { }
}