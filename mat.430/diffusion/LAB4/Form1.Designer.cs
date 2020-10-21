namespace lab4
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.btn1 = new System.Windows.Forms.Button();
            this.btn2 = new System.Windows.Forms.Button();
            this.cmbx2 = new System.Windows.Forms.ComboBox();
            this.cmbx3 = new System.Windows.Forms.ComboBox();
            this.cmbx4 = new System.Windows.Forms.ComboBox();
            this.tbx1 = new System.Windows.Forms.TextBox();
            this.z1 = new ZedGraph.ZedGraphControl();
            this.cmbx1 = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(572, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(104, 24);
            this.label1.TabIndex = 0;
            this.label1.Text = "Задача # ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(556, 71);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(71, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Число узлов";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(556, 100);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(77, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Параметр \"e\"";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(556, 210);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(75, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Погрешность";
            // 
            // btn1
            // 
            this.btn1.Location = new System.Drawing.Point(559, 297);
            this.btn1.Name = "btn1";
            this.btn1.Size = new System.Drawing.Size(80, 30);
            this.btn1.TabIndex = 6;
            this.btn1.Text = "Рисовать";
            this.btn1.UseVisualStyleBackColor = true;
            this.btn1.Click += new System.EventHandler(this.btn1_Click);
            // 
            // btn2
            // 
            this.btn2.Location = new System.Drawing.Point(680, 297);
            this.btn2.Name = "btn2";
            this.btn2.Size = new System.Drawing.Size(80, 30);
            this.btn2.TabIndex = 7;
            this.btn2.Text = "выход";
            this.btn2.UseVisualStyleBackColor = true;
            this.btn2.Click += new System.EventHandler(this.btn2_Click);
            // 
            // cmbx2
            // 
            this.cmbx2.FormattingEnabled = true;
            this.cmbx2.Items.AddRange(new object[] {
            "Гамма 1",
            "Гамма 2",
            "Гамма 3",
            "Гамма 4",
            "Гамма 5",
            "Гамма 6"});
            this.cmbx2.Location = new System.Drawing.Point(667, 166);
            this.cmbx2.Name = "cmbx2";
            this.cmbx2.Size = new System.Drawing.Size(134, 21);
            this.cmbx2.TabIndex = 9;
            this.cmbx2.SelectedIndexChanged += new System.EventHandler(this.cmbx2_SelectedIndexChanged);
            // 
            // cmbx3
            // 
            this.cmbx3.FormattingEnabled = true;
            this.cmbx3.Items.AddRange(new object[] {
            "5",
            "9",
            "17",
            "33",
            "65",
            "100",
            "150",
            "200",
            "250",
            "300",
            "350",
            "425",
            "500"});
            this.cmbx3.Location = new System.Drawing.Point(667, 68);
            this.cmbx3.Name = "cmbx3";
            this.cmbx3.Size = new System.Drawing.Size(93, 21);
            this.cmbx3.TabIndex = 10;
            this.cmbx3.Text = "5";
            // 
            // cmbx4
            // 
            this.cmbx4.FormattingEnabled = true;
            this.cmbx4.Items.AddRange(new object[] {
            "1.0",
            "0.5",
            "0.25",
            "0.125",
            "0.0625",
            "0.03125",
            "0.015625",
            "0.0078125",
            "0.00392625"});
            this.cmbx4.Location = new System.Drawing.Point(667, 100);
            this.cmbx4.Name = "cmbx4";
            this.cmbx4.Size = new System.Drawing.Size(93, 21);
            this.cmbx4.TabIndex = 11;
            this.cmbx4.Text = "0.5";
            // 
            // tbx1
            // 
            this.tbx1.Location = new System.Drawing.Point(667, 207);
            this.tbx1.Name = "tbx1";
            this.tbx1.Size = new System.Drawing.Size(134, 20);
            this.tbx1.TabIndex = 12;
            // 
            // z1
            // 
            this.z1.Location = new System.Drawing.Point(12, 43);
            this.z1.Name = "z1";
            this.z1.ScrollGrace = 0D;
            this.z1.ScrollMaxX = 0D;
            this.z1.ScrollMaxY = 0D;
            this.z1.ScrollMaxY2 = 0D;
            this.z1.ScrollMinX = 0D;
            this.z1.ScrollMinY = 0D;
            this.z1.ScrollMinY2 = 0D;
            this.z1.Size = new System.Drawing.Size(538, 363);
            this.z1.TabIndex = 5;
            this.z1.Load += new System.EventHandler(this.z1_Load);
            // 
            // cmbx1
            // 
            this.cmbx1.FormattingEnabled = true;
            this.cmbx1.Items.AddRange(new object[] {
            "Ex. 1",
            "Ex. 2",
            "Ex. 3",
            "Ex. 4",
            "Ex. 5",
            "Ex. 6"});
            this.cmbx1.Location = new System.Drawing.Point(680, 21);
            this.cmbx1.Name = "cmbx1";
            this.cmbx1.Size = new System.Drawing.Size(121, 21);
            this.cmbx1.TabIndex = 13;
            this.cmbx1.SelectedIndexChanged += new System.EventHandler(this.cmbx1_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(556, 169);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(105, 13);
            this.label2.TabIndex = 14;
            this.label2.Text = "Параметр \"gamma\"";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(556, 251);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(88, 13);
            this.label6.TabIndex = 15;
            this.label6.Text = "Аппроксимация";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "1",
            "2"});
            this.comboBox1.Location = new System.Drawing.Point(667, 248);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(134, 21);
            this.comboBox1.TabIndex = 16;
            this.comboBox1.Text = "1";
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(878, 416);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.cmbx1);
            this.Controls.Add(this.tbx1);
            this.Controls.Add(this.cmbx4);
            this.Controls.Add(this.cmbx3);
            this.Controls.Add(this.cmbx2);
            this.Controls.Add(this.btn2);
            this.Controls.Add(this.btn1);
            this.Controls.Add(this.z1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button btn1;
        private System.Windows.Forms.Button btn2;
        private System.Windows.Forms.ComboBox cmbx2;
        private System.Windows.Forms.ComboBox cmbx3;
        private System.Windows.Forms.ComboBox cmbx4;
        private System.Windows.Forms.TextBox tbx1;
        private ZedGraph.ZedGraphControl z1;
        private System.Windows.Forms.ComboBox cmbx1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox comboBox1;
    }
}

