using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MineWeeper
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //计时器
        private Timer timer1 = new Timer();
        //所用时间
        private int yongshi = 0;
        //游戏是否结束
        private bool over = false;
        //生成雷的行数
        private int hang = 12;
        //生成雷的列数
        private int lie = 12;
        //定义难度（0为简单，1为普通，2为困难，默认为简单）
        private int NanDu = 0;
        //定义地雷数（默认为简单的雷数）
        private int leishu = 10;
        //游戏过程中剩余的地雷数量
        private int restlie;

        //定义属性
        public int Leishu
        {
            get
            { return leishu; }
            set
            {
                leishu = value;
            }

        }
        public int Hang
        {
            get
            { return hang; }
            set
            {
                hang = value;
            }
        }
        public int Lie
        {
            get
            { return lie; }
            set
            {
                lie = value;
            }
        }
        private LeiButton[,] button = new LeiButton[12, 12];

        private void Form1_Load(object sender, EventArgs e)
        {
            Program.form = this; restlie = Leishu;
            label4.Text = "";
            label5.Text = "简单";
            groupBox1.Location = new Point(26, 26);
            groupBox1.Text = "";
            groupBox1.Size = new System.Drawing.Size(908, 488);
            groupBox1.FlatStyle = FlatStyle.Standard;
            lei.Text = "  " + restlie.ToString() + "颗";
            this.Location = new Point(20, 20);
            timer1.Enabled = true;
            Leizheng();
            Bulei();
            this.StartPosition = FormStartPosition.Manual;
            timer1.Tick += new EventHandler(timer1_Tick);
            timer1.Interval = 1000;
        }
        private void Leizheng()
        {
            for (int i = 0; i < lie; i++)
            {
                for (int j = 0; j < hang; j++)
                {
                    button[j, i] = new LeiButton();
                    button[j, i].Location = new Point(3 + i * 30, 6 + j * 30);
                    button[j, i].X = j;
                    button[j, i].Y = i;
                    button[j, i].Youlei = 0;
                    button[j, i].Font = new System.Drawing.Font("宋体", button[j, i].Font.Size, button[j, i].Font.Style);
                    groupBox1.Controls.Add(button[j, i]);
                    button[j, i].MouseUp += new MouseEventHandler(bt_MouseUp);
                }
            }
        }
        private void bt_MouseUp(object sender, MouseEventArgs e)
        {
            if (!over)
            {
                int x, y;
                //获取被点击的Button按钮
                LeiButton b = (LeiButton)sender;
                x = b.X;//x代表button数组的第一个索引
                y = b.Y;//y表示Button数组的第二个索引
                //判断按下的鼠标键是哪个
                switch (e.Button)
                {
                    //按下鼠标左键
                    case MouseButtons.Left:
                        //判断该方格是否被翻开，Tag=0表示方格未被翻开
                        if (Convert.ToInt16(button[x, y].Tag) == 0)
                        {
                            if (button[x, y].Youlei == 0)
                            {
                                button[x, y].Enabled = false;
                                button[x, y].Text = Getdilei(x, y).ToString();
                                Saolei(x, y);
                                if (Win())
                                {
                                    Showlei();
                                    timer1.Enabled = false;
                                    MessageBox.Show("已扫除所有雷！", "扫雷完成");
                                    over = true;
                                }
                            }
                            else
                            {
                                timer1.Enabled = false;
                                b.Enabled = false;
                                xianshi();
                                MessageBox.Show("你挂了", "游戏失败");
                                over = true;
                            }
                        }
                        break;
                    case MouseButtons.Right:

                        if (Convert.ToInt16(button[x, y].Tag) == 1)
                        {
                            button[x, y].Tag = 2;
                            button[x, y].Text = "?";

                        }
                        else if (Convert.ToInt16(button[x, y].Tag) == 2)
                        {
                            button[x, y].Tag = 0;
                            restlie++;
                            button[x, y].Text = null;
                        }
                        else
                        {
                            button[x, y].Tag = 1;
                            button[x, y].Text = "扫";
                            restlie--;

                        }
                        lei.Text = "  " + restlie.ToString() + "颗";
                        if (Win())
                        {
                            MessageBox.Show("已扫除所有雷！", "扫雷完成");
                            timer1.Enabled = false;
                            over = true;
                        }
                        break;
                }
            }
            else
                return;
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            yongshi++;
            if (yongshi < 60)
                label4.Text = yongshi.ToString() + "秒";
            else
                label4.Text = (yongshi / 60).ToString() + "分" + (yongshi % 60).ToString() + "秒";
        }
        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            if(NanDu == 0)
            {
                leishu = 10;
            }
            else if(NanDu == 1)
            {
                leishu = 20;
            }
            else if(NanDu == 2)
            {
                leishu = 30;
            }
            Fuyuan();
        }
        private void Bulei()
        {
            Random rand = new Random();
            for (int i = 0; i < leishu; i++)
            {
                int position_x = rand.Next(hang);
                int position_y = rand.Next(lie);
                if (button[position_x, position_y].Youlei == 0)
                {
                    button[position_x, position_y].Youlei = 1;
                }
                else
                    i = i - 1;
            }
        }
        private int Getdilei(int row, int col)//x代表行，y代表列
        {
            int i, j;
            int around = 0;
            int minRow = (row == 0) ? 0 : row - 1;
            int maxRow = row + 2;
            int minCol = (col == 0) ? 0 : col - 1;
            int maxCol = col + 2;
            for (i = minRow; i < maxRow; i++)
            {
                for (j = minCol; j < maxCol; j++)
                {
                    if (!(i >= 0 && i < hang && j >= 0 && j < lie))//判断是否在扫雷区域
                        continue;
                    if (button[i, j].Youlei == 1) around++;
                }
            }
            return around;
        }
        private void Saolei(int row, int col)
        {

            int minrow1 = (row == 0) ? 0 : row - 1;
            int mincol1 = (col == 0) ? 0 : col - 1;
            int maxrow1 = row + 2;
            int maxcol1 = col + 2;
            int leishuliang = Getdilei(row, col);
            if (leishuliang == 0)
            {
                button[row, col].Enabled = false;
                for (int m = minrow1; m < maxrow1; m++)
                {
                    for (int n = mincol1; n < maxcol1; n++)
                    {
                        if (!(m >= 0 && m < hang && n >= 0 && n < lie))
                            continue;
                        if (!(m == row && n == col) && button[m, n].Enabled == true && Convert.ToInt16(button[m, n].Tag) == 0)
                            Saolei(m, n);
                        //判断该处是否标记为有雷，有雷该处不作任何变化，无雷控件Enable属性变为false
                        if (Convert.ToInt16(button[m, n].Tag) == 0)
                            button[m, n].Enabled = false;
                        button[m, n].Text = Getdilei(m, n).ToString();
                        if (button[m, n].Text == "0")
                            button[m, n].Text = string.Empty;
                    }
                }
            }
        }
        private bool Win()
        {
            int zongshu = 0;
            for (int i = 0; i < hang; i++)
            {
                for (int j = 0; j < lie; j++)
                {
                    if (button[i, j].Youlei == 1 && Convert.ToInt16(button[i, j].Tag) == 1)
                        zongshu++;
                }
            }
            if (zongshu == leishu && restlie == 0)
                return true;
            else
                return false;
        }
        private void Showlei()
        {
            for (int i = 0; i < hang; i++)
            {
                for (int j = 0; j < lie; j++)
                    if (button[i, j].Youlei == 1)
                    {
                        button[i, j].Text = "雷";
                    }
            }
        }
        private void xianshi()
        {
            int l = 0;
            for (int i = 0; i < hang; i++)
            {
                for (int j = 0; j < lie; j++)
                {
                    if (button[i, j].Youlei == 1)
                    {
                        button[i, j].Text = "炸";
                        l++;
                    }
                }
            }

        }
        public void Fuyuan()
        {
            for (int i = 0; i < hang; i++)
            {
                for (int j = 0; j < lie; j++)
                {
                    button[i, j].Tag = 0;
                    button[i, j].Enabled = true;
                    button[i, j].Text = string.Empty;
                    button[i, j].BackgroundImage = null;
                    if (button[i, j].Youlei == 1)
                        button[i, j].Youlei = 0;
                }

            }
            Bulei();
            yongshi = 0;
            over = false;
            restlie = leishu;
            lei.Text = "  " + restlie.ToString() + "颗";
        }

        private void 简单ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            label5.Text = "简单";
            NanDu = 0;
        }

        private void 普通ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            label5.Text = "普通";
            NanDu = 1;
        }

        private void 困难ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            label5.Text = "困难";
            NanDu = 2;
        }
    }
    
}
