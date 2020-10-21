using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using ZedGraph;
namespace Lagranj
{
    public partial class Form1 : Form
    {
        double E, e;
        double K, k, lo;
        double[] xp, yp;
        int Nx, Ny;
        double C1, C2;
        double A, B;
        double r, q;
        double beta, mu;
        double F, y;
        double[,] Psi;
        double[,] prevPsi;
        double[,] f;
        double gamma;
        double dx, dy;
        double R;
        double err1, err2, err;
        double[,] Func;

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox2.SelectedIndex == 0) //Central scheme
            {
                beta = 0.2;
                mu = 0.01;
                F = 0.0125;
                r = 10;
                q = 2*Math.PI;
                k = 0.5;
                lo = 1;

                textBox6.Text = beta.ToString();
                textBox12.Text = mu.ToString();
                textBox10.Text = F.ToString();
                textBox1.Text = r.ToString();
                textBox2.Text = q.ToString();
                textBox13.Text = lo.ToString();
                textBox16.Text = k.ToString();

            }
            else if (comboBox2.SelectedIndex == 1) //Direction scheme
            {
                beta = 2 * Math.Pow(10, -11);
                mu = 0.0029;
                F = Math.PI/210;
                r = 17;
                q = 6;
                k = 0.143;
                lo = 1;

                textBox6.Text = beta.ToString();
                textBox12.Text = mu.ToString();
                textBox10.Text = F.ToString();
                textBox1.Text = r.ToString();
                textBox2.Text = q.ToString();
                textBox13.Text = lo.ToString();
                textBox16.Text = k.ToString();
            }

            else if (comboBox2.SelectedIndex == 2)//Samarksiy scheme
            {
                beta = 0.02;
                mu = 0.001;
                F = Math.PI / 2 * Math.Pow(10, -3);
                r = 11;
                q = 6;
                k = 0.05;
                lo = 1;

                textBox6.Text = beta.ToString();
                textBox12.Text = mu.ToString();
                textBox10.Text = F.ToString();
                textBox1.Text = r.ToString();
                textBox2.Text = q.ToString();
                textBox13.Text = lo.ToString();
                textBox16.Text = k.ToString();
            }
        }

        public Form1()
        {
            InitializeComponent();
        }
        private void Parameters()
        {
            beta = Convert.ToDouble(textBox6.Text);
            mu = Convert.ToDouble(textBox12.Text);
            F = Convert.ToDouble(textBox10.Text);
            y = Convert.ToDouble(textBox17.Text);
            r = Convert.ToDouble(textBox1.Text);
            q = Convert.ToDouble(textBox2.Text);
            Nx = Convert.ToInt32(textBox3.Text);
            Ny = Convert.ToInt32(textBox4.Text);
            E = Convert.ToDouble(textBox14.Text);
            e = Convert.ToDouble(textBox15.Text);
            K = Convert.ToDouble(textBox8.Text);
            dx = r / (Nx - 1.0f);
            dy = q / (Ny - 1.0f);
            R = beta * dx / (2.0f * mu);
            A = -(beta / (2 * mu))
                + Math.Sqrt(Math.Pow(beta / (2 * mu), 2) + Math.Pow(Math.PI / q, 2));
            B = -(beta / (2 * mu))
                - Math.Sqrt(Math.Pow(beta / (2 * mu), 2) + Math.Pow(Math.PI / q, 2));

            C1 = (1 - Math.Exp(B * r)) / (Math.Exp(A * r) - Math.Exp(B * r));
            C2 = 1 - C1;
            err1 = 0;
            err2 = 0;
            err = 0;
            Psi = new double[Nx + 1, Ny + 1];
            prevPsi = new double[Nx + 1, Ny + 1];
            f = new double[Nx + 1, Ny + 1]; //f(i,j) = F * sin(Math.pi * y / q)
            
            xp = new double[Nx + 1];
            yp = new double[Ny + 1];
            if (comboBox1.SelectedIndex == 0) //Central scheme
            {
               gamma = 1;       
            }
            else if (comboBox1.SelectedIndex == 1) //Direction scheme
            {
                
                gamma = 1 + Math.Abs(R);
            }

            else if (comboBox1.SelectedIndex == 2)//Samarksiy scheme
            {
                gamma = 1 + Math.Pow(R, 2)
                             / (1 + Math.Abs(R));    
            }
            else if (comboBox1.SelectedIndex == 3) //Buleev & Timuhin
            {

                gamma = 1 + Math.Abs(Math.Pow(R, 3))
                             / (1 + Math.Abs(R) + Math.Pow(R, 2));
            }
            else if (comboBox1.SelectedIndex == 4) //Buleev
            {

                gamma = 1 + Math.Pow(R, 2) * (1 + 2 * Math.Abs(R))
                             / (3 + 3 * Math.Abs(R) + 2 * Math.Pow(R, 2));
            }
            else if (comboBox1.SelectedIndex == 5)//Iliin
            {

                gamma = R == 0 ? 0 : R * (Math.Exp(R) + Math.Exp(-R))
                                        / (Math.Exp(R) - Math.Exp(-R));
                    //Math.Abs(R) == 0 ? 0 : R * 1 / Math.Tanh(R);
                    //Math.Abs(R) >= 0.00000000001 ? R * 1/Math.Tanh(R) : 0;

            }
            
            for (int i = 1; i <= Nx; ++i)
            {
                xp[i] = (double)(i - 1) * dx;
            }
            for (int i = 1; i <= Ny; ++i)
            {
                yp[i] = (double)(i - 1) * dy;

            }
            for (int i = 1; i <= Nx; ++i)
            {
                for (int j = 1; j <= Ny; ++j)
                {
                    Psi[i, j] = 0;
                    prevPsi[i, j] = 0;  
                    f[i, j] = F * Math.Sin(Math.PI * yp[j] / q);
                }
            }

        }
        private void Form1_Load(object sender, EventArgs e)
        {
            groupBox1.Visible = true;
        }
        public double function(double x)
        {
 
            double result = F / 
                            (mu * Math.Pow((Math.PI/q), 2))
                            * (C1 * Math.Exp(A*x) + C2 * Math.Exp(B * x) - 1)
                            * Math.Sin(Math.PI * y / q);

           return result;

        }
        public void approximation()                                 
        {
            for (int t = 0; t < K; ++t)
            {
                err = 0;

                for (int i = 2; i < Nx; ++i)
                {

                    for (int j = 2; j < Ny; ++j)
                    {
                        Psi[i, j] = (-f[i, j] 
                                    + Psi[i - 1, j] * (gamma - R) * mu / (dx * dx) 
                                    + Psi[i, j - 1] * mu / (dy * dy)
                                    + Psi[i + 1, j] * (gamma + R) * mu / (dx * dx) 
                                    + Psi[i, j + 1] * mu / (dy * dy)) 
                                  / (2 * mu * (gamma / (dx * dx) + 1 / (dy * dy))); 
                    }
                }
                //Calculate Error
                
                for (int i = 2; i < Nx; ++i)
                {
                    for (int j = 2; j < Ny; ++j)
                    {
                        err1 = Math.Abs(prevPsi[i, j] - Psi[i, j]);
                        err = Math.Max(err, err1);
                    }
                }
                if (err < e)
                {
                    textBox18.Text = t.ToString();
                    break;
                }
                else if (err > E)
                {
                    textBox18.Text = t.ToString();
                    break;
                }
                else
                {
                    textBox18.Text = t.ToString();
                }
                textBox7.Text = err.ToString();
                prevPsi = (double[,])(Psi.Clone());
                
                
            }
                  

        }

        
        public void Draw()
        {

            Parameters();
            PointPairList list1 = new PointPairList();
            GraphPane myPane = ctrl.GraphPane;
            myPane.CurveList.Clear();
            for (double x = 0.0; x <= r; x += 0.0001)
            {

                list1.Add(x, function(x));
            }
            LineItem line1 = myPane.AddCurve("Тестовая функция", list1, Color.Black, SymbolType.None);
            line1.Line.IsVisible = true;
            line1.Symbol.Fill.Color = Color.Black;
            line1.Symbol.Fill.Type = FillType.Solid;
            line1.Symbol.Size = 2.0f;
            ctrl.AxisChange();
            ctrl.Invalidate();
            myPane.Title.Text = " ";
            PointPairList list2 = new PointPairList();

            approximation();
            for (int  i = 1; i <= Nx; ++i)
            {
                int j = (int)(y / dy  + 1);
                list2.Add(xp[i], Psi[i,j]);
            }
            

            LineItem line2 = myPane.AddCurve("", list2, Color.Red, SymbolType.None);
            line2.Line.IsVisible = true;
            line2.Symbol.Fill.Color = Color.Red;
            line2.Symbol.Fill.Type = FillType.Solid;
            line2.Symbol.Size = 6.0f;
            ctrl.AxisChange();
            ctrl.Invalidate();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = true;
            for (int i = 0; i < 10; i++)
            {
                Thread.Sleep(60);
                this.Opacity = this.Opacity - 0.1;
            }
            for (int i = 0; i < 10; i++)
            {
                Thread.Sleep(60);
                this.Opacity = this.Opacity + 0.1;
            }
           
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Draw();
        }

        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void ctrl_Load(object sender, EventArgs e)
        {

        }

       
        
    }
}
