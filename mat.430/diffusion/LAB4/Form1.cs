using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ZedGraph;

namespace lab4
{
    public partial class Form1 : Form
    {
        private int n; // число узлов
        private double h; // шаг сетки
        //
        private double e; // параметр е
        private double c;
        private double dzeta0;
        private double eta0;
        private double psi0;
        private double phi0;
        //

        private double dzeta1;
        private double eta1;
        private double psi1;
        private double phi1;
        private double[] gamma;
        private double[] R;
        private const int T = 100; // кол-во точек
        private double[] x; // массив аргументов
        private double[] xp;
        private double[] u; // массив ф-ций
        double[] S;         // сплайн
        private double[] a; // функция a(x)
        private double[] b; // функция b(x)
        private double[] f; // функция f(x)
        private double err;
        private double err1;
        private double err2;

        // коэффициенты прогонки
        private double[] A;
        private double[] B;
        private double[] C;
        private double[] alfa;
        private double[] beta;
        private double[] F;

        // Для ZedGraph
        private GraphPane panel1; // панель для рисования
        private PointPairList exact, approximate;

        private void Parameters()
        {
            // инициализация параметров задачи
            n = Convert.ToInt32(cmbx3.Text);

            e = Convert.ToDouble(cmbx4.Text);




            h = 1.0 / (n - 1.0);
            xp = new double[T + 1];
            x = new double[n + 1];
            u = new double[n + 1];
            R = new double[n + 1];
            gamma = new double[n + 1];
            a = new double[n + 1];
            b = new double[n + 1];
            f = new double[n + 1];
            S = new double[T + 1];
            A = new double[n + 1];
            B = new double[n + 1];
            C = new double[n + 1];
            alfa = new double[n + 1];
            beta = new double[n + 1];
            F = new double[n + 1];
            err = 0;
            err1 = 0;
            err2 = 0;

        }

        public double function(double t) // Решения ДУ
        {
            double res = 0;
            if (cmbx1.SelectedIndex == 0)//Ex1
            {
                a[0] = 1;
                dzeta0 = 0;
                eta0 = 10;
                phi0 = -10;
                phi1 = -1;
                double c2 = (phi0 - dzeta0 * phi1) /
                            (dzeta0 + eta0 * a[0] - (dzeta0 * Math.Exp(-a[0] / e)));

                double c1 = phi1 - Math.Exp(-a[0] / e) * c2;
                res = c1 + c2 * Math.Exp(-(a[0] * t) / e);

            }
            else if (cmbx1.SelectedIndex == 1)//Ex2
            {
                res = (t * (1 - t)) / 2
                      + (Math.Exp(-1 / e) - Math.Exp(-2 / (e * (1 + t))))
                      / (2 * (1 - Math.Exp(-1 / e)));

            }
            else if (cmbx1.SelectedIndex == 2)//Ex3
            {
                res = (1.0 - Math.Exp((1.0 - Math.Pow(1.0 + t, 3.0)) / e))
                     / (1.0 - Math.Exp(-7.0 / e))
                     - Math.Log(1.0 + t) / 2.0;
            }
            else if (cmbx1.SelectedIndex == 3)//Ex4
            {
                res = (t / (1 + t)) +
                      (Math.Exp(-1 / e) - Math.Exp(-2 * t / (e * (1 + t))))
                    / (2 * (1 - Math.Exp(-1 / e)));
            }
            else if (cmbx1.SelectedIndex == 4)//Ex5
            {
                res = (2 * t / (1 + t))
                     + (Math.Exp(-1 / e) - Math.Exp(-2 *t / (e * (1 + t))))
                     / (1 - Math.Exp(-1 / e));
            }
            else if (cmbx1.SelectedIndex == 5)//Ex6
            {
                /*
                double E1 = t / Math.Pow(e, 0.5) < 50 ? Math.Exp(-t / Math.Pow(e, 0.5)) : 0;
                double E2 = (1 - t) / Math.Pow(e, 0.5) < 50 ? Math.Exp(-(1 - t) / Math.Pow(e, 0.5)) : 0;
                double E3 = 1 / Math.Pow(e, 0.5) < 50 ? Math.Exp(-1 / Math.Pow(e, 0.5)) : 0;
                */
                double E1 = t  < 50 ? Math.Exp(-t / Math.Pow(e, 0.5)) : 0;
                double E2 = t < 50 ? Math.Exp((-1 + t) / Math.Pow(e, 0.5)) : 0;
                double E3 = t < 50 ? Math.Exp(-1 / Math.Pow(e, 0.5)) : 0;
                res = (E1 + E2)
                     / (1 + E3)
                     - Math.Pow(Math.Cos(t * Math.PI), 2);
            }

            return res;
        }

        private void CalcEx() // точное решение
        {
            exact = new PointPairList();
            for (int i = 1; i <= T; i++)
            {
                xp[i] = (i - 1.0) / (T - 1.0); // сетка
                S[i] = function(xp[i]);
                exact.Add(xp[i], S[i]);
            }
        }
        private void CalcParam() //a,b,f
        {
            if (cmbx1.SelectedIndex == 0)//Ex1
            {
                dzeta0 = 0;
                dzeta1 = 1.0;
                eta0 = 10.0;
                eta1 = 0;
                phi0 = -10.0;
                phi1 = -1.0;
                for (int i = 1; i <= n; ++i)
                {
                    x[i] = (i - 1.0) / (n - 1.0);
                    a[i] = 1; //a[i] = 2/( 1 + x[i]) ^2
                    b[i] = 0;
                    f[i] = 0;
                    R[i] = a[i] * h / (2 * e);
                }
            }
            else if (cmbx1.SelectedIndex == 1)//Ex2
            {
                dzeta0 = 1.0; dzeta1 = 1.0;
                eta0 = 0; eta1 = 0;
                phi0 = 0.5 * Math.Exp(-1 / e);
                phi1 = 0;
                for (int i = 1; i <= n; ++i)
                {
                    x[i] = (i - 1.0) / (n - 1.0);
                    a[i] = 2 * e / (1 + x[i])
                         - 2 / Math.Pow((1 + x[i]), 2);
                    b[i] = 0;
                    f[i] = (1 - 2 * x[i]) / Math.Pow((1 + x[i]), 2)
                         * (e * (1 + x[i]) - 1)
                         - e;
                    f[i] = -f[i];
                    R[i] = a[i] * h / (2.0 * e);
                }

            }
            else if (cmbx1.SelectedIndex == 2)//Ex3
            {
                dzeta0 = 1.0; dzeta1 = 1.0;
                eta0 = 1.0 / 3.0; eta1 = 0;
                phi0 = e / 6.0
                     - 1.0 / (1.0 - Math.Exp(-7.0 / e));
                phi1 = 1.0 - Math.Log(2.0) / 2.0;
                for (int i = 1; i <= n; ++i)
                {
                    x[i] = (i - 1.0) / (n - 1.0);
                    a[i] = 3.0 * Math.Pow((1 + x[i]), 2)
                         - 2.0 * e / (1 + x[1]);
                    b[i] = 0;
                    f[i] = 3.0 * e / (2.0 * Math.Pow((1 + x[i]), 2))
                         - 3.0 * (1 + x[i]) / 2.0;
                    f[i] = -f[i];
                    R[i] = a[i] * h / (2.0 * e);
                }

            }
            else if (cmbx1.SelectedIndex == 3)//Ex4
            {
                dzeta0 = 2.0; dzeta1 = 2.0;
                eta0 = 1.0; eta1 = 4.0;
                phi0 = -(1 + e
                     + 1.0 / (1.0 - Math.Exp(-1.0 / e)));
                phi1 = 1.0 + e + Math.Exp(-1.0 / e)
                     / (1.0 - Math.Exp(-1.0 / e));
                for (int i = 1; i <= n; ++i)
                {
                    x[i] = (i - 1.0) / (n - 1.0);
                    a[i] = 2.0 / Math.Pow((1 + x[i]), 2);
                    b[i] = 4.0 / Math.Pow((1 + x[i]), 3);
                    f[i] = ((1.0 - 2.0 * x[i]) / (1 + x[i])
                         - e - (Math.Exp(-1 / e)) / (1 - Math.Exp(-1 / e)))
                         * 2.0 / Math.Pow((1 + x[i]), 3);
                    f[i] = -f[i];
                    R[i] = a[i] * h / (2.0 * e);
                }

            }
            else if (cmbx1.SelectedIndex == 4)//Ex5
            {
                dzeta0 = 1.0; dzeta1 = 1.0;
                eta0 = 0; eta1 = 0;
                phi0 = -1.0;
                phi1 = 1.0;
                for (int i = 1; i <= n; ++i)
                {
                    x[i] = (i - 1.0) / (n - 1.0);
                    a[i] = 2.0 * e / (1 + x[i])
                         + 2.0 / Math.Pow((1 + x[i]), 2);
                    b[i] = 0;
                    f[i] = 4.0 / Math.Pow((1 + x[i]), 4);
                    f[i] = -f[i];
                    R[i] = a[i] * h / (2 * e);
                }

            }
            else if (cmbx1.SelectedIndex == 5)//Ex6
            {
                dzeta0 = 1.0; dzeta1 = 1.0;
                eta0 = 0; eta1 = 0;
                phi0 = 0;
                phi1 = 0;
                double E1, E2, E3;
                double eq;
                for (int i = 1; i <= n; ++i)
                {
                    x[i] = (i - 1.0) / (n - 1.0);
                    a[i] = 0;
                    b[i] = Math.Pow((1 + x[i]), 2);
                    /*
                    E1 = x[i] / Math.Pow(e, 0.5) < 50 ? Math.Exp(-x[i] / Math.Pow(e, 0.5)) : 0;
                    E2 = (1 - x[i]) / Math.Pow(e, 0.5) < 50 ? Math.Exp(-(1 - x[i]) / Math.Pow(e, 0.5)) : 0;
                    E3 = 1 / Math.Pow(e, 0.5) < 50 ? Math.Exp(-1 / Math.Pow(e, 0.5)) : 0;
                    */
                    E1 = x[i] < 50 ? Math.Exp(-x[i] / Math.Pow(e, 0.5)) : 0;
                    E2 = x[i] < 50 ? Math.Exp((-1 + x[i]) / Math.Pow(e, 0.5)) : 0;
                    E3 = x[i] < 50 ? Math.Exp(-1 / Math.Pow(e, 0.5)) : 0;


                    eq = (E1 + E2) / (e * (E3 + 1)) + 2 * Math.PI * Math.PI * Math.Cos(2 * x[i] * Math.PI);
                    f[i] = e * eq - b[i] * ((E1 + E2) / (1 + E3)
                         - Math.Pow(Math.Cos(x[i] * Math.PI), 2));
                    f[i] = -f[i];
                    R[i] = a[i] * h / (2 * e);
                }

            }

            f[n] = phi1;
            f[1] = phi0;
        }
        void CalcGamma()
        {

            if (cmbx2.SelectedIndex == 0) //Central scheme
            {
                for (int i = 1; i <= n; ++i)
                {
                    gamma[i] = 1;
                }
            }
            else if (cmbx2.SelectedIndex == 1) //Direction scheme
            {
                for (int i = 1; i <= n; ++i)
                {
                    gamma[i] = 1 + Math.Abs(R[i]);
                }
            }

            else if (cmbx2.SelectedIndex == 2)//Samarksiy scheme
            {
                for (int i = 1; i <= n; ++i)
                {
                    gamma[i] = 1 + Math.Pow(R[i], 2)
                             / (1 + Math.Abs(R[i]));
                }
            }
            else if (cmbx2.SelectedIndex == 3) //Buleev & Timuhin
            {
                for (int i = 1; i <= n; ++i)
                {
                    gamma[i] = 1 + Math.Abs(Math.Pow(R[i], 3))
                             / (1 + Math.Abs(R[i]) + Math.Pow(R[i], 2));
                }
            }
            else if (cmbx2.SelectedIndex == 4) //Buleev
            {
                for (int i = 1; i <= n; ++i)
                {
                    gamma[i] = 1
                             + Math.Pow(R[i], 2) * (1 + 2 * Math.Abs(R[i]))
                             / (3 + 3 * Math.Abs(R[i]) + 2 * Math.Pow(R[i], 2));
                }
            }
            else if (cmbx2.SelectedIndex == 5)//Iliin
            {
                for (int i = 1; i <= n; ++i)
                {
                    gamma[i] = R[i] == 0 ? 0 : R[i] * (Math.Exp(R[i]) + Math.Exp(-R[i]))
                                           / (Math.Exp(R[i]) - Math.Exp(-R[i]));
                    //Math.Abs(R[i]) == 0 ? 0 : R[i] * 1 / Math.Tanh(R[i]);
                    //Math.Abs(R[i]) >= 0.00000000001 ? R[i] * 1/Math.Tanh(R[i]) : 0;

                }
            }

        }
        private void CalcApp() // приближенное решение
        {
            approximate = new PointPairList();
            CalcParam();
            CalcGamma();

            //Calculate A,B,C; a, b, f = const for 1st Ex
            B[1] = dzeta0 + e * eta0 / h;
            C[1] = e * eta0 / h;
            B[n] = dzeta1 + e * eta1 / h;
            A[n] = e * eta1 / h;
            for (int i = 2; i < n; ++i)
            {
                A[i] = (e / (h * h)) * (gamma[i] - R[i]);
                B[i] = 2 * e * gamma[i] / (h * h) + b[i];
                C[i] = (e / (h * h)) * (gamma[i] + R[i]);
            }
            //Approximate
            alfa[1] = C[1] / B[1];
            beta[1] = f[1] / B[1];
            for (int i = 2; i < n; ++i)
            {
                alfa[i] = C[i]
                     / (B[i] - alfa[i - 1] * A[i]);
                beta[i] = (f[i] + beta[i - 1] * A[i])
                     / (B[i] - alfa[i - 1] * A[i]);
            }
            u[n] = (f[n] + beta[n - 1] * A[n]) / (B[n] - alfa[n - 1] * A[n]);
            for (int i = n - 1; i > 1; --i)
            {
                u[i] = alfa[i] * u[i + 1] + beta[i];
            }
           
            if (comboBox1.SelectedIndex == 0)
            {
                u[1] = alfa[1] * u[2] + beta[1];
            }
            else if (comboBox1.SelectedIndex == 1)
            {
                u[1] = (phi0 - (f[1] * eta0 * h) / (2 - h * a[1] / e)
                    + u[2] * (eta0 * e) / (h - h * h * a[1] / (2 * e)))
                    / (dzeta0
                    + (eta0 * e) / (h - h * h * a[1] / (2 * e))
                    + (b[1] * h * eta0 * e) / (2 * e - h * a[1]));
            }

            for (int i = 1; i <= n; i++)
            {
                // Вычисление погрешности
                err1 = Math.Max(err1, Math.Abs(u[i] - function(x[i])));
                err2 = Math.Max(err2, Math.Abs(function(x[i])));
                err = (err1 / err2) * 100;

                //use this as argument for a,b,f
                approximate.Add(x[i], u[i]);

            }
            
        }

        private void DrawGraph() // построение графика
        {
            panel1.CurveList.Clear();
            panel1.AddCurve("Точное решение", exact, Color.Red, SymbolType.None);
            panel1.AddCurve("Приближенное решение", approximate, Color.Green, SymbolType.Circle);
            z1.AxisChange();
            z1.Refresh();
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            panel1 = z1.GraphPane;
            panel1.Chart.Fill = new Fill(Color.FromArgb(255, 255, 255),
                Color.FromArgb(240, 240, 240), 90F);
            panel1.Fill.Color = this.BackColor;
            panel1.Border.IsVisible = false;
            panel1.Title.IsVisible = false;
            panel1.XAxis.Title.IsVisible = false;
            panel1.YAxis.Title.IsVisible = false;
            panel1.XAxis.MajorGrid.IsVisible = true;
            panel1.YAxis.MajorGrid.IsVisible = true;
            panel1.IsFontsScaled = false;
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            GraphPane panel1 = z1.GraphPane;
            panel1.CurveList.Clear();
            PointPairList list = new PointPairList();
            Parameters();
            CalcEx();
            CalcApp();
            DrawGraph();
            tbx1.Text = err.ToString();
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)//a
        {

        }

        private void cmbx1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void cmbx2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged_1(object sender, EventArgs e)
        {

        }

        private void z1_Load(object sender, EventArgs e)
        {

        }

    }
}
