using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Configuration;

namespace MineGame
{
    public partial class Form1 : Form
    {
        private Map map = null;//地图对象
        private int time = 0;//游戏的时间长度，单位是秒
        private int rows=0;
        private int cols=0;
        private int mines=0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //创建地图对象，并初始化，动态显示和地图上的格子对象对应的按钮
            rows = Convert.ToInt32(ConfigurationManager.AppSettings["Rows"]);
            cols = Convert.ToInt32(ConfigurationManager.AppSettings["Cols"]);
            mines = Convert.ToInt32(ConfigurationManager.AppSettings["Mines"]);
           
            map = new Map(rows,cols,mines);

            //计算宽度和高度
            int width = this.pnlButtons.Width / cols;
            int height = this.pnlButtons.Height / rows;

            // 根据地图上的格子，创建按钮
            for (int i=0;i<map.AllCells.Count;i++)
            {
                var cell = map.AllCells[i];

                Button btn = new Button();
                btn.Text = "";
                btn.Width = width;
                btn.Height = height; // 按钮的宽和高
                btn.Left = (i % cols) * width;
                btn.Top = i / cols * height;  //x，y坐标计算
                btn.Tag = i; //下标保存在Tag属性中的
                btn.DoubleClick += btn_DoubleClick;
                btn.Click += Open;

                this.pnlButtons.Controls.Add(btn);
            }

            time = 0;
            timer1.Enabled = true;//开始游戏的计时
        }
        
        //格子的双击事件
        void btn_DoubleClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void Open(object sender, EventArgs e)
        {
            //调用地图的翻开方法，按照游戏规则翻开格子
            Button  btn = sender as Button;
            map.Open(Convert.ToInt32(btn.Tag));

            //重新显示所有的按钮
            for (int i = 0; i < pnlButtons.Controls.Count; i++)
            {
                Button bt = pnlButtons.Controls[i] as Button;
                int index = Convert.ToInt32(bt.Tag);
                var cell = map.AllCells[index];
                if(cell.IsOpen)
                {
                    bt.Text = cell.Character;//显示文字
                    bt.BackColor = Color.AliceBlue;
                }
            }

            //调用地图的裁判方法，看游戏是否结束
            int result = map.Judge();
            if (result == 0)
            {
                MessageBox.Show("踩到地雷了");
                timer1.Enabled = false;
            }
            else if (result == 1)
            {
                MessageBox.Show(string.Format("恭喜你完成游戏，用时{0}秒",time));
                //以后考虑排行榜
                timer1.Enabled = false;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            time++; // 定时到了，加1秒钟
        }

        private void mnuNewGame_Click(object sender, EventArgs e)
        {
            if (timer1.Enabled == true)
            {
                MessageBox.Show("还在游戏进程中，不能开启新游戏");
                return;
            }

            //开始新游戏
            map.Init(rows,cols,mines); //地图的初始化
            //重新显示所有的按钮
            for (int i = 0; i < pnlButtons.Controls.Count; i++)
            {
                Button bt = pnlButtons.Controls[i] as Button;
                bt.Text = "";
                bt.BackColor = Color.FromArgb(244, 244, 244);             
            }

            //重新计时
            time = 0;
            timer1.Enabled = true;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
