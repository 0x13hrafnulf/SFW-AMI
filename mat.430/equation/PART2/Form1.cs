using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ZedGraph;
using System.IO;

namespace part2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        
            Parameters();
           
        }

        private int N, M, L = 100, k;
        private double E, tmax, h, tau, Curant;

        private double[] psi0, psi1, phi;
        private double T1, T2; //For Ex4

        private double t = 0;
        private double[] xe, x, u, v;
        double theta, gam, v1, v2;
        private GraphPane pane;
        private PointPairList exact, approx;
        private double err1, err2, err;

        // коэффициенты прогонки
        private double A0;
        private double B0;
        private double C0;
        private double[] alfa;
        private double[] beta;
        private double[] F;
        private double[] A;
        private double[] B;
        private double[] C;


        private void Parameters()
        {
            E = Convert.ToDouble(cmbE.SelectedItem);  //параметр диффузии
            tmax = Convert.ToDouble(cmbTT.SelectedItem); // конечный момент времени
            N = Convert.ToInt32(cmbN.SelectedItem);   // число узлов по пространству
            M = Convert.ToInt32(cmbM.SelectedItem);  // число узлов по времени
            k = Convert.ToInt32(cmbk.SelectedItem);  //параметр в точном решении        

            T1 = Convert.ToDouble(textBox2.Text);
            T2 = Convert.ToDouble(textBox3.Text);

            h = 1.0 / (N - 1.0);
            tau = tmax / M;

            Curant = (E * tau) / (h * h);

            tbCurant.Text = Curant.ToString();

            xe = new double[L + 1];
            x = new double[N + 1];

            u = new double[N + 1];
            v = new double[N + 1];

            err1 = 0;
            err2 = 0; 
            err = 0;

            alfa = new double[N + 1];
            beta = new double[N + 1];
            F = new double[N + 1];
            A = new double[N + 1];
            B = new double[N + 1];
            C = new double[N + 1];

            psi0 = new double[M + 1];
            psi1 = new double[M + 1];
            phi = new double[N + 1];

            if (cmbTask.SelectedIndex == 0) // параметр  theta:  выбор схемы
            {
                theta = 0;           
            }
            else if (cmbTask.SelectedIndex == 1)
            {
                theta = 0.5;
            }
            else if(cmbTask.SelectedIndex == 2)
            {
                theta = 1.0;         
            }
            else if(cmbTask.SelectedIndex == 3)
            {
                theta = Math.Max(0.5, 1 - 1.0 / (2.0 * Curant));
            }
            else if(cmbTask.SelectedIndex == 4)
            {
                theta = Math.Max(0.5, 1 - 3.0 / (4.0 * Curant));
            }
            else if (cmbTask.SelectedIndex == 5)
            {
                theta = 0.5 * ( 1 - 1.0 / (6.0 * Curant));
            }


            A0 = (1 - theta) * Curant;
            C0 = (1 - theta) * Curant;
            B0 = 1 - A0 - C0;

            C[1] = 0;
            B[1] = 1;           
            A[N] = 0;
            B[N] = 1;
            for (int i = 2; i < N; ++i)
            {
                A[i] = theta * Curant;
                C[i] = theta * Curant;
                B[i] = 1 + A[i] + C[i];
            }



            for (int i = 1; i <= N; i++)
            {
                x[i] = (double)(i - 1) / (N - 1);
            }
        }
        public double Erf(double val)
        {
            double result, s, p, a1, a2, a3, a4, a5;
            result = 1.0f;

            if (val < 0) result = -1.0;
            if (val < 0) val = -val;
            

            p = 0.3275911;
            a1 = 0.254829592;
            a2 = -0.284496736;
            a3 = 1.421413741;
            a4 = -1.453152027;
            a5 = 1.061405429;
            s = 1.0 / (1 + p * val);

            result *= 1.0
                   - (a1 * s 
                   + a2 * s * s 
                   + a3 * s * s * s 
                   + a4 * s * s * s * s
                   + a5 * s * s * s * s * s)
                   * Math.Exp(- (val * val));


           

            return result;
        }
        public double Function(double x, double t)
        {
            double result = 0;
            //Ex1
            if (comboBox1.SelectedIndex == 0)
            {
                result = Math.Sin(Math.PI * k * x) 
                       * Math.Exp(-Math.Pow(Math.PI * k, 2) * E * t)
                       + x * CalcPsi(N) + (1 - x) * CalcPsi(1);
            }
            //Ex2
            else if(comboBox1.SelectedIndex == 1)
            {
                gam = Math.Sqrt(k * Math.PI / (2 * E));
                v1 = (Math.Cos(gam * x) * Math.Cosh(gam * (2.0 - x)) 
                    - Math.Cosh(gam * x) * Math.Cos(gam * (2.0 - x))) 
                    / (Math.Cosh(2.0 * gam) - Math.Cos(2.0 * gam));

                v2 = (Math.Sin(gam * x) * Math.Sinh(gam * (2.0 - x)) 
                    - Math.Sinh(gam * x) * Math.Sin(gam * (2.0 - x))) 
                    / (Math.Cosh(2.0 * gam) - Math.Cos(2.0 * gam));
                result = v1 * Math.Cos(Math.PI * k * t) + v2 * Math.Sin(Math.PI * k * t);
            }
            //Ex3
            else if (comboBox1.SelectedIndex == 2)
            {
                gam = Math.Sqrt(k * Math.PI / (2 * E));
                v1 = (Math.Cos(gam * x) * Math.Cosh(gam * (2.0 - x)) 
                    - Math.Cosh(gam * x) * Math.Cos(gam * (2.0 - x))) 
                    / (Math.Cosh(2.0 * gam) - Math.Cos(2.0 * gam));

                v2 = (Math.Sin(gam * x) * Math.Sinh(gam * (2.0 - x)) 
                    - Math.Sinh(gam * x) * Math.Sin(gam * (2.0 - x))) 
                    / (Math.Cosh(2.0 * gam) - Math.Cos(2.0 * gam));
                result = v1 * Math.Sin(Math.PI * k * t) - v2 * Math.Cos(Math.PI * k * t);
            }
            //Ex4
            else if (comboBox1.SelectedIndex == 3)
            {
                double temp = t == 0 ? 0.000000000001 : t;
                double z = (2.0 * x - 1.0) / (4.0 * Math.Sqrt(E * temp));
                result = (T2 + T1)/ 2.0
                       + (T2 - T1)/ 2.0 
                       * Erf(z);
            }

            return result;
        }

        private void CalcApp()
        {
            
            if (t == 0)
            {
                CalcPhi();
                v = (double[])(phi.Clone());
            }
           else
            {
                //Calculate A,B,C; a, b, f = const for 1st Ex
                u[1] = CalcPsi(1);
                u[N] = CalcPsi(N);
                //Approximate
                CalcF();
                alfa[1] = C[1] / B[1];
                beta[1] = F[1] / B[1];
                for (int i = 2; i < N; ++i)
                {
                    alfa[i] = C[i]
                        / (B[i] - alfa[i - 1] * A[i]);
                    beta[i] = (F[i] + beta[i - 1] * A[i])
                        / (B[i] - alfa[i - 1] * A[i]);
                }
                //u[N] = (F[N] + beta[N - 1] * A) / (B - alfa[N - 1] * A);
                
                for (int i = N - 1; i > 1; --i)
                {
                    u[i] = alfa[i] * u[i + 1] + beta[i];
                }
                //u[1] = alfa[1] * u[2] + beta[1];
        

                v = (double[])(u.Clone());
            }

            approx = new PointPairList();              
            for (int i = 1; i <= N; i++)
            {
                // Вычисление погрешности
                err1 = Math.Max(err1, Math.Abs(v[i] - Function(x[i], t)));
                err2 = err2 == 0 ? 0.000000000001 : Math.Max(err2, Math.Abs(Function(x[i], t)));
                err = Math.Max(err, (err1 / err2) * 100);
                textBox1.Text = err.ToString();
                approx.Add(x[i], v[i]);
            }
        }
        public void CalcPhi()
        {
            
            //Ex1
            if (comboBox1.SelectedIndex == 0)
            {
                for (int i = 1; i <= N; i++)
                {
                    phi[i] = Math.Sin(Math.PI * k * x[i]) 
                           + x[i] * CalcPsi(N) + (1 - x[i]) * CalcPsi(1);
                }
            }
            //Ex2
            else if(comboBox1.SelectedIndex == 1)
            {
               for (int i = 1; i <= N; i++)
                {
                    gam = Math.Sqrt(k * Math.PI / (2 * E));
                    phi[i] = (Math.Cos(gam * x[i]) * Math.Cosh(gam * (2.0 - x[i])) 
                           - Math.Cosh(gam * x[i]) * Math.Cos(gam * (2.0 - x[i]))) / (Math.Cosh(2.0 * gam) 
                           - Math.Cos(2.0 * gam));;
                }
            }
            //Ex3
            else if (comboBox1.SelectedIndex == 2)
            {
               for (int i = 1; i <= N; i++)
                {
                    gam = Math.Sqrt(k * Math.PI / (2 * E));
                    phi[i] = (Math.Sin(gam * x[i]) * Math.Sinh(gam * (2.0 - x[i]))
                           - Math.Sinh(gam * x[i]) * Math.Sin(gam * (2.0 - x[i]))) / (Math.Cosh(2.0 * gam) 
                           - Math.Cos(2.0 * gam));;
                    phi[i] = -phi[i];
                }
            }
            //Ex4
            else if (comboBox1.SelectedIndex == 3)
            {
                for (int i = 1; i <= N; i++)
                {
                    if(x[i] >= 0 && x[i] < 0.5) phi[i] = T1;
                    else if(x[i] == 0.5) phi[i] = (T2 + T1) / 2.0;
                    else if (x[i] > 0.5 && x[i] <= 1.0) phi[i] = T2;
                }
            }
        }
        public double CalcPsi(double j)
        {
            double result = 0;
            //Calc psi
            if (comboBox1.SelectedIndex == 0)//Ex1
            {           
                if(j == 1)
                    result = 3;
                else
                    result = 0;
            }
            else if (comboBox1.SelectedIndex == 1)//Ex2
            {
                if(j == 1)
                    result = Math.Cos(Math.PI * k * t);
                else
                    result = 0;
            }
            else if (comboBox1.SelectedIndex == 2)//Ex3
            {
                if(j == 1)
                    result = Math.Sin(Math.PI * k * t);
                else
                    result = 0; 
            }
            else if (comboBox1.SelectedIndex == 3)//Ex4
            {
                double z;
                if (j == 1)
                {
                    z = - 1.0 / (4.0 * Math.Sqrt(E * t));
                }
                else
                {
                    z = 1.0 / (4.0 * Math.Sqrt(E * t));

                }
                result = (T2 + T1) / 2.0
                           + (T2 - T1) / 2.0
                           * Erf(z);
            }

            return result;
        }
        public void CalcF()
        {
            for (int i = 2; i < N; ++i)
            {
                F[i] = A0 * v[i-1] + B0 * v[i] + C0 * v[i + 1];
            }
            F[1] = v[1]; 
            F[N] = v[N];
        }
 
        private void Graph() //Exact Solution
        {
            exact = new PointPairList(); 
            for (int i = 1; i <= L; i++)
            {
                xe[i] = (i - 1.0) / (L - 1.0);
                exact.Add(xe[i], Function(xe[i], t));
            }
        }


        private void btnDraw_Click(object sender, EventArgs e)
        {
            GraphPane pane = zedGraph.GraphPane;
            pane.CurveList.Clear();
            PointPairList list = new PointPairList();

            Parameters();
            
            CalcApp();
            Graph();
            DrawAll();
            
            timer.Start();

        }
        private void DrawAll()
        {
            pane.CurveList.Clear();
            if (chbBV1.Checked)
                pane.AddCurve("Точное решение", exact, Color.OrangeRed, SymbolType.None);
            if (chbBV2.Checked)
                pane.AddCurve("Схема", approx, Color.Blue, SymbolType.Circle);

            zedGraph.AxisChange();
            zedGraph.Refresh();
        }
        private void Form1_Load_1(object sender, EventArgs e)
        {
            pane = zedGraph.GraphPane;
            pane.Chart.Fill = new Fill(Color.FromArgb(255, 255, 255),
            Color.FromArgb(240, 240, 240), 90F);
            pane.Fill.Color = this.BackColor;
            pane.Border.IsVisible = false;
            pane.Title.IsVisible = false;
            pane.XAxis.Title.IsVisible = false;
            pane.YAxis.Title.IsVisible = false;
            pane.XAxis.MajorGrid.IsVisible = true;
            pane.YAxis.MajorGrid.IsVisible = true;
            pane.IsFontsScaled = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }


        private void timer_Tick(object sender, EventArgs e)
        {

            GraphPane pane = zedGraph.GraphPane;
            pane.CurveList.Clear();
            PointPairList list = new PointPairList();
            
            CalcApp();
            Graph();
            DrawAll();

            tbTime.Text = "Time: " + t.ToString();
            t += tau;
            t = Math.Round(t, 3);
            if (t > tmax)
            {
                timer.Stop();
                t = 0;
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            t += tau;
            GraphPane pane = zedGraph.GraphPane;
            pane.CurveList.Clear();
            PointPairList list = new PointPairList();

            CalcApp();
            Graph();
            DrawAll();

        }

        private void zedGraph_Load(object sender, EventArgs e)
        {

        }

        private void cmbTask_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void cmbE_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Задача_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void tbT_TextChanged(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

    }

}