namespace MineWeeper
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.lei = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.简单ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.简单ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.普通ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.困难ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label2 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Location = new System.Drawing.Point(68, 92);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(509, 481);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "groupBox1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(1032, 92);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 15);
            this.label1.TabIndex = 1;
            this.label1.Text = "总共雷数";
            // 
            // lei
            // 
            this.lei.AutoSize = true;
            this.lei.Location = new System.Drawing.Point(1032, 135);
            this.lei.Name = "lei";
            this.lei.Size = new System.Drawing.Size(97, 15);
            this.lei.TabIndex = 2;
            this.lei.Text = "总共雷数显示";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(1032, 253);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 15);
            this.label3.TabIndex = 3;
            this.label3.Text = "所用时间";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(1032, 292);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(97, 15);
            this.label4.TabIndex = 4;
            this.label4.Text = "所用时间显示";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(665, 472);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(318, 101);
            this.button1.TabIndex = 5;
            this.button1.Text = "开始";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.简单ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1358, 28);
            this.menuStrip1.TabIndex = 6;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 简单ToolStripMenuItem
            // 
            this.简单ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.简单ToolStripMenuItem1,
            this.普通ToolStripMenuItem,
            this.困难ToolStripMenuItem});
            this.简单ToolStripMenuItem.Name = "简单ToolStripMenuItem";
            this.简单ToolStripMenuItem.Size = new System.Drawing.Size(81, 24);
            this.简单ToolStripMenuItem.Text = "难度设置";
            // 
            // 简单ToolStripMenuItem1
            // 
            this.简单ToolStripMenuItem1.Name = "简单ToolStripMenuItem1";
            this.简单ToolStripMenuItem1.Size = new System.Drawing.Size(181, 26);
            this.简单ToolStripMenuItem1.Text = "简单（10雷）";
            this.简单ToolStripMenuItem1.Click += new System.EventHandler(this.简单ToolStripMenuItem1_Click);
            // 
            // 普通ToolStripMenuItem
            // 
            this.普通ToolStripMenuItem.Name = "普通ToolStripMenuItem";
            this.普通ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.普通ToolStripMenuItem.Text = "普通（20雷）";
            this.普通ToolStripMenuItem.Click += new System.EventHandler(this.普通ToolStripMenuItem_Click);
            // 
            // 困难ToolStripMenuItem
            // 
            this.困难ToolStripMenuItem.Name = "困难ToolStripMenuItem";
            this.困难ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.困难ToolStripMenuItem.Text = "困难（30雷）";
            this.困难ToolStripMenuItem.Click += new System.EventHandler(this.困难ToolStripMenuItem_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(1035, 382);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(67, 15);
            this.label2.TabIndex = 7;
            this.label2.Text = "当前难度";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(1038, 417);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(97, 15);
            this.label5.TabIndex = 8;
            this.label5.Text = "当前难度显示";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1358, 622);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.lei);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Timer timer2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lei;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 简单ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 简单ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 普通ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 困难ToolStripMenuItem;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label5;
    }
}

