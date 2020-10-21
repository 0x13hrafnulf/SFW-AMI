namespace part2
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
            this.tbCurant = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.tbTime = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.zedGraph = new ZedGraph.ZedGraphControl();
            this.btnDraw = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.chbBV2 = new System.Windows.Forms.CheckBox();
            this.chbBV1 = new System.Windows.Forms.CheckBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.cmbN = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.cmbE = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.Задача = new System.Windows.Forms.Label();
            this.cmbTask = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.cmbk = new System.Windows.Forms.ComboBox();
            this.txtbT = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.cmbM = new System.Windows.Forms.ComboBox();
            this.cmbTT = new System.Windows.Forms.ComboBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // tbCurant
            // 
            this.tbCurant.Location = new System.Drawing.Point(129, 317);
            this.tbCurant.Name = "tbCurant";
            this.tbCurant.Size = new System.Drawing.Size(100, 20);
            this.tbCurant.TabIndex = 61;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(33, 320);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(42, 13);
            this.label5.TabIndex = 29;
            this.label5.Text = "Курант";
            // 
            // timer
            // 
            this.timer.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // tbTime
            // 
            this.tbTime.Location = new System.Drawing.Point(129, 343);
            this.tbTime.Name = "tbTime";
            this.tbTime.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.tbTime.Size = new System.Drawing.Size(100, 20);
            this.tbTime.TabIndex = 57;
            this.tbTime.UseWaitCursor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(9, 493);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 27);
            this.button2.TabIndex = 53;
            this.button2.Text = "Выход";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // zedGraph
            // 
            this.zedGraph.Location = new System.Drawing.Point(240, 2);
            this.zedGraph.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.zedGraph.Name = "zedGraph";
            this.zedGraph.ScrollGrace = 0D;
            this.zedGraph.ScrollMaxX = 0D;
            this.zedGraph.ScrollMaxY = 0D;
            this.zedGraph.ScrollMaxY2 = 0D;
            this.zedGraph.ScrollMinX = 0D;
            this.zedGraph.ScrollMinY = 0D;
            this.zedGraph.ScrollMinY2 = 0D;
            this.zedGraph.Size = new System.Drawing.Size(672, 476);
            this.zedGraph.TabIndex = 56;
            this.zedGraph.Load += new System.EventHandler(this.zedGraph_Load);
            // 
            // btnDraw
            // 
            this.btnDraw.Location = new System.Drawing.Point(9, 441);
            this.btnDraw.Name = "btnDraw";
            this.btnDraw.Size = new System.Drawing.Size(101, 37);
            this.btnDraw.TabIndex = 52;
            this.btnDraw.Text = "Вычислить";
            this.btnDraw.UseVisualStyleBackColor = true;
            this.btnDraw.Click += new System.EventHandler(this.btnDraw_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(129, 441);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(100, 37);
            this.button1.TabIndex = 59;
            this.button1.Text = "Шаг";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(35, 346);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(40, 13);
            this.label6.TabIndex = 62;
            this.label6.Text = "Время";
            // 
            // chbBV2
            // 
            this.chbBV2.AutoSize = true;
            this.chbBV2.Checked = true;
            this.chbBV2.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chbBV2.Location = new System.Drawing.Point(9, 418);
            this.chbBV2.Name = "chbBV2";
            this.chbBV2.Size = new System.Drawing.Size(149, 17);
            this.chbBV2.TabIndex = 1;
            this.chbBV2.Text = "Приближенное решение";
            this.chbBV2.UseVisualStyleBackColor = true;
            // 
            // chbBV1
            // 
            this.chbBV1.AutoSize = true;
            this.chbBV1.Checked = true;
            this.chbBV1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chbBV1.Location = new System.Drawing.Point(9, 395);
            this.chbBV1.Name = "chbBV1";
            this.chbBV1.Size = new System.Drawing.Size(109, 17);
            this.chbBV1.TabIndex = 0;
            this.chbBV1.Text = "Точное решение";
            this.chbBV1.UseVisualStyleBackColor = true;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(129, 369);
            this.textBox1.Name = "textBox1";
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 64;
            this.textBox1.UseWaitCursor = true;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(23, 372);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(75, 13);
            this.label7.TabIndex = 65;
            this.label7.Text = "Погрешность";
            // 
            // cmbN
            // 
            this.cmbN.FormattingEnabled = true;
            this.cmbN.Items.AddRange(new object[] {
            "5",
            "9",
            "17",
            "33",
            "65",
            "129"});
            this.cmbN.Location = new System.Drawing.Point(120, 151);
            this.cmbN.Name = "cmbN";
            this.cmbN.Size = new System.Drawing.Size(100, 21);
            this.cmbN.TabIndex = 19;
            this.cmbN.Text = "5";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 151);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(91, 26);
            this.label3.TabIndex = 12;
            this.label3.Text = "Число узлов \r\nпо пространству";
            // 
            // cmbE
            // 
            this.cmbE.FormattingEnabled = true;
            this.cmbE.Items.AddRange(new object[] {
            "1",
            "0.5",
            "0.25",
            "0.125",
            "0.0625",
            "0.03125",
            "0.015625",
            "0.0078125",
            "0.00390625"});
            this.cmbE.Location = new System.Drawing.Point(120, 115);
            this.cmbE.Name = "cmbE";
            this.cmbE.Size = new System.Drawing.Size(100, 21);
            this.cmbE.TabIndex = 18;
            this.cmbE.Text = "1";
            this.cmbE.SelectedIndexChanged += new System.EventHandler(this.cmbE_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 118);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(68, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "Параметр Е";
            // 
            // Задача
            // 
            this.Задача.AutoSize = true;
            this.Задача.Location = new System.Drawing.Point(27, 53);
            this.Задача.Name = "Задача";
            this.Задача.Size = new System.Drawing.Size(39, 13);
            this.Задача.TabIndex = 10;
            this.Задача.Text = "Схема";
            this.Задача.Click += new System.EventHandler(this.Задача_Click);
            // 
            // cmbTask
            // 
            this.cmbTask.FormattingEnabled = true;
            this.cmbTask.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6"});
            this.cmbTask.Location = new System.Drawing.Point(120, 50);
            this.cmbTask.Name = "cmbTask";
            this.cmbTask.Size = new System.Drawing.Size(100, 21);
            this.cmbTask.TabIndex = 17;
            this.cmbTask.Text = "1";
            this.cmbTask.SelectedIndexChanged += new System.EventHandler(this.cmbTask_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(38, 85);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(13, 13);
            this.label4.TabIndex = 25;
            this.label4.Text = "k";
            // 
            // cmbk
            // 
            this.cmbk.FormattingEnabled = true;
            this.cmbk.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5"});
            this.cmbk.Location = new System.Drawing.Point(120, 82);
            this.cmbk.Name = "cmbk";
            this.cmbk.Size = new System.Drawing.Size(100, 21);
            this.cmbk.TabIndex = 62;
            this.cmbk.Text = "1";
            // 
            // txtbT
            // 
            this.txtbT.AutoSize = true;
            this.txtbT.Location = new System.Drawing.Point(38, 227);
            this.txtbT.Name = "txtbT";
            this.txtbT.Size = new System.Drawing.Size(14, 13);
            this.txtbT.TabIndex = 61;
            this.txtbT.Text = "T";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 187);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(76, 26);
            this.label1.TabIndex = 63;
            this.label1.Text = "Число шагов \r\nпо времени";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // cmbM
            // 
            this.cmbM.FormattingEnabled = true;
            this.cmbM.Items.AddRange(new object[] {
            "5",
            "9",
            "17",
            "33",
            "65",
            "129",
            "257",
            "513"});
            this.cmbM.Location = new System.Drawing.Point(120, 187);
            this.cmbM.Name = "cmbM";
            this.cmbM.Size = new System.Drawing.Size(100, 21);
            this.cmbM.TabIndex = 64;
            this.cmbM.Text = "5";
            // 
            // cmbTT
            // 
            this.cmbTT.FormattingEnabled = true;
            this.cmbTT.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "7"});
            this.cmbTT.Location = new System.Drawing.Point(120, 219);
            this.cmbTT.Name = "cmbTT";
            this.cmbTT.Size = new System.Drawing.Size(100, 21);
            this.cmbTT.TabIndex = 65;
            this.cmbTT.Text = "2";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4"});
            this.comboBox1.Location = new System.Drawing.Point(120, 19);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(100, 21);
            this.comboBox1.TabIndex = 66;
            this.comboBox1.Text = "1";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(27, 22);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(43, 13);
            this.label8.TabIndex = 67;
            this.label8.Text = "Задача";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(108, 280);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(20, 13);
            this.label9.TabIndex = 68;
            this.label9.Text = "T2";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(108, 254);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(20, 13);
            this.label10.TabIndex = 69;
            this.label10.Text = "T1";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(130, 251);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(90, 20);
            this.textBox2.TabIndex = 70;
            this.textBox2.Text = "0";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(130, 277);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(90, 20);
            this.textBox3.TabIndex = 71;
            this.textBox3.Text = "0";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label11.Location = new System.Drawing.Point(6, 254);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(96, 26);
            this.label11.TabIndex = 72;
            this.label11.Text = "Параметры \r\nдля задачи №4";
            this.label11.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label11);
            this.groupBox2.Controls.Add(this.textBox3);
            this.groupBox2.Controls.Add(this.textBox2);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.comboBox1);
            this.groupBox2.Controls.Add(this.cmbTT);
            this.groupBox2.Controls.Add(this.cmbM);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.txtbT);
            this.groupBox2.Controls.Add(this.cmbk);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.cmbTask);
            this.groupBox2.Controls.Add(this.Задача);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.cmbE);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.cmbN);
            this.groupBox2.Location = new System.Drawing.Point(-1, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(241, 299);
            this.groupBox2.TabIndex = 51;
            this.groupBox2.TabStop = false;
            this.groupBox2.UseCompatibleTextRendering = true;
            this.groupBox2.Enter += new System.EventHandler(this.groupBox2_Enter);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(924, 532);
            this.Controls.Add(this.chbBV2);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.chbBV1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.tbTime);
            this.Controls.Add(this.tbCurant);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.zedGraph);
            this.Controls.Add(this.btnDraw);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load_1);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer timer;
        private System.Windows.Forms.TextBox tbTime;
        private System.Windows.Forms.Button button2;
        private ZedGraph.ZedGraphControl zedGraph;
        private System.Windows.Forms.Button btnDraw;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox tbCurant;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.CheckBox chbBV2;
        private System.Windows.Forms.CheckBox chbBV1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox cmbN;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox cmbE;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label Задача;
        private System.Windows.Forms.ComboBox cmbTask;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox cmbk;
        private System.Windows.Forms.Label txtbT;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cmbM;
        private System.Windows.Forms.ComboBox cmbTT;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Label label11;
        public System.Windows.Forms.GroupBox groupBox2;
    }
}

