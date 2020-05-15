using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestDynamicController
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            //在窗口上添加一个文本框
            TextBox tb = new TextBox();
            tb.Name = "txtName";
            tb.Text = "Tom";
            tb.Top=btnSave.Top;
            tb.Left = btnSave.Left + btnSave.Width;
            //用方法订阅控件的某个事件，使之成为事件处理方法
            tb.TextChanged += ShowInfo;

            this.Controls.Add(tb);
        }

        private void ShowInfo(object sender, EventArgs e)
        {
            MessageBox.Show("文本框中的文本改变了");
        }
    }
}
