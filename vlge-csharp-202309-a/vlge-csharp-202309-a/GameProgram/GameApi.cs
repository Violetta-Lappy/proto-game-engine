using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VLGameProgram {
    public struct Vec2 {
        private float x;
        private float y;
        public Vec2(float arg_x, float arg_y) {
            x = arg_x;
            y = arg_y;
        }
        public float X { get => x; set => x = value; }
        public float Y { get => y; set => y = value; }
    }

    public struct Vec3 {
        private float x;
        private float y;
        private float z;
        public Vec3(float arg_x, float arg_y, float arg_z) {
            x = arg_x;
            y = arg_y;
            z = arg_z;
        }
        public float X { get => x; set => x = value; }
        public float Y { get => y; set => y = value; }
        public float Z { get => z; set => z = value; }
    }

    public struct Vec2Int {
        private int x;
        private int y;
        public Vec2Int(int arg_x, int arg_y) {
            x = arg_x;
            y = arg_y;
        }
        public int X { get => x; set => x = value; }
        public int Y { get => y; set => y = value; }
    }

    public struct Vec3Int {
        private int x;
        private int y;
        private int z;
        public Vec3Int(int arg_x, int arg_y, int arg_z) {
            x = arg_x;
            y = arg_y;
            z = arg_z;
        }
        public int X { get => x; set => x = value; }
        public int Y { get => y; set => y = value; }
        public int Z { get => z; set => z = value; }
    }

    public struct Transform { }
}
