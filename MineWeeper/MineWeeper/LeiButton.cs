using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MineWeeper
{
    public class LeiButton : Button
    {
        //返回按钮所在的矩阵的点，二维数组的两个坐标
        private int x;
        private int y;
        //记录该个控件下是否有雷，0表示无雷，1表示有雷
        private int youlei;
        public LeiButton()
        {
            Tag = 0;     ///0表示未翻开，1表示翻开
            Size = new System.Drawing.Size(30, 30);
        }

        public int X
        {
            get
            { return x; }
            set
            { x = value; }
        }
        public int Y
        {
            get
            { return y; }
            set
            { y = value; }
        }
        public int Youlei
        {
            get
            { return youlei; }
            set
            { youlei = value; }
        }

    }
}
