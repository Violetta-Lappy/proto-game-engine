/*
Copyright 2023 Violetta & Lappy - hoanglongplanner

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

//https://gafferongames.com/post/fix_your_timestep/
//https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/1.2.hello_window_clear/hello_window_clear.cpp

#include <engine/Program.h>
#include <fmt/format.h>

class KGraphicApi {
public:
    static const int K_OpenGL = 0;
    static const int K_Vulkan = 1;
    static const int K_WebGPU = 2;
};

int main(int argc, char* argv[]) {   
    
    int tech = 2;

    switch (tech) {
        case KGraphicApi::K_OpenGL:
            {
                fmt::println("OpenGL choose. Opening context !!");
            }
            break;
        case KGraphicApi::K_Vulkan:
            {
                fmt::println("Vulkan choose. Opening context !!");
            }
            break;
        case KGraphicApi::K_WebGPU:
            {
                fmt::println("WebGPU choose. Opening context !!");
            }
            break;
        default:
            {
                fmt::println("None choose. Applicaton exit !!");
            }
            break;
    }

    return 0;
}



