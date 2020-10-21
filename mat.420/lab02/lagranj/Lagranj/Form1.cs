using System;
using System.Numerics;
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
        //Reading

        int Nz;
        double dz;
        double w;
        double f1, fn;
        double sigma;
        double err1E, err2E, errE;
        double err1H, err2H, errH;
        double zm;


        //Complex part
        Complex[] zp;
        Complex B0, C0, An, Bn;
        Complex A, B, C;
        Complex[] E, H;
        Complex C_k;
        Complex fi;
        Complex i;
        Complex dummy1;
        Complex dummy2;
        Complex C_dz;
        Complex C_w, C_mu;
        Complex C_f1, C_fn;
        Complex C_sigma;
        Complex C_zm;

        Complex[] alfa, beta;

        public Form1()
        {
            InitializeComponent();
        }
        private void Parameters()
        {
            //Read
            Nz = Convert.ToInt32(textBox1.Text);
            w  = Convert.ToDouble(textBox6.Text);
            f1 = Convert.ToDouble(textBox3.Text);
            fn = Convert.ToDouble(textBox4.Text);           
            sigma = Convert.ToDouble(textBox2.Text);
            zm = Convert.ToDouble(textBox5.Text);
            dz = zm / (Nz - 1.0f);
            err1E = 0;
            err2E = 0;
            errE = 0;
            err1H = 0;
            err2H = 0;
            errH = 0;

            dummy1 = 1;
            dummy2 = 2;
            //Complex
            C_zm = zm;
            C_dz = dz;
            i = new Complex(0, 1);
            C_w = w;
            C_mu = 4 * Math.PI * Math.Pow(10, -7);
            C_f1 = f1;
            C_fn = fn;
            C_sigma = sigma;
            C_k = (dummy1 - i) * Complex.Sqrt(C_mu * C_w * C_sigma/dummy2);

            B0 = 1;
            C0 = 0;
            An = 0;
            Bn = 1;
            A = dummy1 + C_dz * C_dz * C_sigma * C_w * C_mu * i;
            B = 2;
            C = 1;


            H = new Complex[Nz + 1];
            E = new Complex[Nz + 1];
            alfa = new Complex[Nz + 1];
            beta = new Complex[Nz + 1];
            //f(i,j) = F * sin(Math.pi * y / q)

            zp = new Complex[Nz + 1];
            
            for (int j = 1; j < Nz + 1; ++j)
            {
                zp[j] = (double)(j - 1) * dz;
            }
            

        }


        private void Form1_Load(object sender, EventArgs e)
        {
            groupBox1.Visible = true;
        }
        public double functionH(double z)
        {
            Complex result = new Complex(0, 0);
            result = C_k * Complex.Cosh(C_k * z) 
                    * (C_fn - C_f1*Complex.Cosh(C_k * C_zm))
                    / (i * C_w * C_mu * Complex.Sinh(C_k * C_zm))
                    - C_f1 * C_sigma * Complex.Sinh(C_k * z) / C_k;

            if (comboBox3.SelectedIndex == 0)
            {
                return result.Real;
            }
            else
            {
                return result.Imaginary;
            }

        }
        public double functionE(double z)
        {
            Complex result = new Complex(0, 0);
            result = Complex.Sinh(C_k * z)
                   * (C_fn - C_f1 * Complex.Cosh(C_k * C_zm))
                   / Complex.Sinh(C_k * C_zm)
                   + C_f1 * Complex.Cosh(C_k * z);
            if (comboBox3.SelectedIndex == 0)
            {
                return result.Real;
            }
            else
            {
                return result.Imaginary;
            }
            

        }
        public void approximation()                                 
        {
            if (comboBox1.SelectedIndex == 0)
            {

                E[1] = C_f1;
                E[Nz] = C_fn;

                alfa[1] = C0 / B0;
                beta[1] = C_f1 / B0;
                //F[j] == 0
                for (int j = 2; j <= Nz; ++j)
                {
                    alfa[j] = C
                        / (B - alfa[j - 1] * A);
                    beta[j] = (beta[j - 1] * A)
                        / (B - alfa[j - 1] * A);
                }
                //E[Nz-1] = (C_fn + beta[Nz - 1] * An) / (Bn - alfa[Nz - 1] * An);

                for (int j = Nz - 1; j > 1; --j)
                {
                    E[j] = alfa[j] * E[j + 1] + beta[j];
                }
                //E[0] = alfa[0] * E[1] + beta[0];


                for (int j = 1; j < Nz; ++j)
                {
                    H[j] = (E[j+1] - E[j]) / (C_dz * i * C_w * C_mu);
                }
                H[Nz] = H[Nz - 2] - C_dz * C_sigma * E[Nz - 2];
            }
            else
            {
                E[1] = C_f1;
                H[1] = (C_fn - Complex.Cosh(C_k * C_zm) * C_f1)
                     / (i * C_w * C_mu * Complex.Sinh(C_k * C_zm) / C_k);


                for (int j = 2; j <= Nz; ++j)
                {
                    H[j] = H[j - 1] * Complex.Cosh(C_k * C_dz) 
                         - E[j - 1] * C_sigma * Complex.Sinh(C_k * C_dz) / C_k;

                    E[j] = H[j - 1] * i * C_w * C_mu * Complex.Sinh(C_k * C_dz) / C_k 
                         + E[j - 1] * Complex.Cosh(C_k * C_dz);
                        
                }
            }

  
        }
        void calcError()
        {

            for (int j = 1; j <= Nz; j++)
            {
                if (comboBox3.SelectedIndex == 0)
                {
                    //H
                    err1H = Math.Max(err1H, Math.Abs(H[j].Real - functionH(zp[j].Real)));
                    err2H = Math.Max(err2H, Math.Abs(functionH(zp[j].Real)));
                    errH = (err1H / err2H) * 100;
                    textBox7.Text = errH.ToString();
                    //E
                    err1E = Math.Max(err1E, Math.Abs(E[j].Real - functionE(zp[j].Real)));
                    err2E = Math.Max(err2E, Math.Abs(functionE(zp[j].Real)));
                    errE = (err1E / err2E) * 100;
                    textBox8.Text = errE.ToString();

                }
                else
                {
                    //H
                    err1H = Math.Max(err1H, Math.Abs(H[j].Imaginary - functionH(zp[j].Real)));
                    err2H = Math.Max(err2H, Math.Abs(functionH(zp[j].Real)));
                    errH = (err1H / err2H) * 100;
                    textBox7.Text = errH.ToString();
                    //E
                    err1E = Math.Max(err1E, Math.Abs(E[j].Imaginary - functionE(zp[j].Real)));
                    err2E = Math.Max(err2E, Math.Abs(functionE(zp[j].Real)));
                    errE = (err1E / err2E) * 100;
                    textBox8.Text = errE.ToString();
                }

            }
        }


        public void Draw()
        {

            Parameters();
            PointPairList He = new PointPairList();
            GraphPane Pane1 = ctrl1.GraphPane;
            Pane1.CurveList.Clear();
            for (double z = 0.0; z <= zm; z += 0.0001)
            {

                He.Add(z, functionH(z));
            }
            LineItem line1 = Pane1.AddCurve("Тестовая функция", He, Color.Black, SymbolType.None);
            line1.Line.IsVisible = true;
            line1.Symbol.Fill.Color = Color.Black;
            line1.Symbol.Fill.Type = FillType.Solid;
            line1.Symbol.Size = 2.0f;
            ctrl1.AxisChange();
            ctrl1.Invalidate();
            Pane1.Title.Text = "H";

            PointPairList Ee = new PointPairList();
            GraphPane Pane2 = ctrl2.GraphPane;
            Pane2.CurveList.Clear();
            for (double z = 0.0; z <= zm; z += 0.0001)
            {
                Ee.Add(z, functionE(z));
            }
            LineItem line2 = Pane2.AddCurve("Тестовая функция", Ee, Color.Black, SymbolType.None);
            line2.Line.IsVisible = true;
            line2.Symbol.Fill.Color = Color.Black;
            line2.Symbol.Fill.Type = FillType.Solid;
            line2.Symbol.Size = 2.0f;
            ctrl2.AxisChange();
            ctrl2.Invalidate();
            Pane2.Title.Text = "E";

            
            approximation();
            calcError();
            PointPairList list1 = new PointPairList();
            for (int j = 1; j <= Nz; ++j)
            {
                if (comboBox3.SelectedIndex == 0)
                {
                    list1.Add(zp[j].Real, H[j].Real);
                }
                else
                {
                    list1.Add(zp[j].Real, H[j].Imaginary);
                }
            }
            LineItem line3 = Pane1.AddCurve("", list1, Color.Red, SymbolType.None);
            line3.Line.IsVisible = true;
            line3.Symbol.Fill.Color = Color.Red;
            line3.Symbol.Fill.Type = FillType.Solid;
            line3.Symbol.Size = 6.0f;
            ctrl1.AxisChange();
            ctrl1.Invalidate();


            PointPairList list2 = new PointPairList();
            for (int j = 1; j <= Nz; ++j)
            {
                if (comboBox3.SelectedIndex == 0)
                {
                    list2.Add(zp[j].Real, E[j].Real);
                }
                else 
                {
                    list2.Add(zp[j].Real, E[j].Imaginary);
                }  
            }
            LineItem line4 = Pane2.AddCurve("", list2, Color.Red, SymbolType.None);
            line4.Line.IsVisible = true;
            line4.Symbol.Fill.Color = Color.Red;
            line4.Symbol.Fill.Type = FillType.Solid;
            line4.Symbol.Size = 6.0f;
            ctrl2.AxisChange();
            ctrl2.Invalidate();
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = true;
            for (int j = 0; j < 10; j++)
            {
                Thread.Sleep(60);
                this.Opacity = this.Opacity - 0.1;
            }
            for (int j = 0; j < 10; j++)
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
