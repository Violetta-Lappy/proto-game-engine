namespace PROJECT_Program {
    public class AppProgramData {
        //PRIVATE: Variable
        private string str_programName = $"PROGRAM - TEMPLATE - PLEASE CHANGE SETTING IN {nameof(AppProgramData)}";
        private int i32_screenWidth = 800; //def: 800
        private int i32_screenHeight = 600; //def: 600

        //PUBLIC: Function, Builder Design Pattern
        public string Get_ProgramName() { return str_programName; }
        public int Get_ScreenWidth() { return i32_screenWidth; }
        public int Get_ScreenHeight() { return i32_screenHeight; }
        public AppProgramData Set_ProgramName(string arg_name) {
            str_programName = arg_name;
            return this;
        }
        public AppProgramData Set_ScreenWidth(int arg_value) {
            i32_screenWidth = arg_value;
            return this;
        }
        public AppProgramData Set_ScreenHeight(int arg_value) {
            i32_screenHeight = arg_value;
            return this;
        }
    }
}