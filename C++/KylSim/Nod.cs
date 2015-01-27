using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace KylSim
{
    public class Nod : VVS
    {
        //variabler
        private double pressure;
        private bool adjustable;
        private string old_str;
        private double sumFlow = 0.0;
        private double old_sumFlow = 0.0;
        private double inFlow = 0.0;
        private double outFlow = 0.0;
        private double i;
        private double m;

        //konstruktor med parametrar
        public Nod(double pressure, bool adjustable, string name, Graphics canvas, int x, int y) : base(name, canvas, x, y)
        {
            this.pressure = pressure;
            this.adjustable = adjustable;
            this.old_str = "";
            i = 0.001;
            m = 0.05;
        }

        //funktioner
        //returnerar trycket
        public override double getPressure()
        {
            return this.pressure;
        }

        //ritar ut nodemn samt nodens namn
        public override void drawCompenent()
        {
            Pen circle = new Pen(Color.Red);
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            //ritar ut cirkeln
            canvas.DrawEllipse(circle, (float)x, (float)y, 10, 10);
            //skriver ut namnet på noden
            canvas.DrawString(name, font, brush, (float)x+10, (float)y-15);
        }

        //skriver ut trycket i noden
        public override void display()
        {
            Brush brush = new SolidBrush(Color.Gainsboro);
            Font font = new Font("Courier", 8);
            //skriver över det gamla värdet
            string value = "Tryck: " + old_str;
            canvas.DrawString(value, font, brush, (float)x + 10, (float)y + 15);

            //skriver ut det nya värdet
            brush = new SolidBrush(Color.Black);
            value = "Tryck: " + pressure.ToString("0.0");
            canvas.DrawString(value, font, brush, (float)x + 10, (float)y + 15);
        }

        //ändrar inflödet till noden
        public override void add_summaflode(double flow)
        {
            //utflöde
            if (flow < 0)
            {
                this.outFlow = flow;
            }
            //inflöde
            else
            {
                this.inFlow = flow;
            }
            this.sumFlow = this.inFlow + this.outFlow;
        }

        //reglerar trycket
        public override void dynamik()
        {
            this.old_str = pressure.ToString("0.0");
            // om reglerbar
            if (adjustable)
            {
                if (Math.Abs(sumFlow) > 0.1)
                {
                    if ((sumFlow * old_sumFlow) < 0 && Math.Abs(sumFlow) > Math.Abs(old_sumFlow))
                    {
                        m *= 0.8;
                    }
                    else
                    {
                        m *= 1.05;
                    }
                    if (m * Math.Abs(sumFlow) > (0.8 * pressure)) 
                    {
                        m = 0.8 * pressure / Math.Abs(sumFlow);
                    }
                    if (m < 0.0001)
                    {
                        m = 0.0001;
                    }
                }
                i += m * sumFlow;
                pressure = sumFlow * m * 0.25 + i;
                if (pressure < 0.001)
                {
                    pressure = 0.001;
                }
            }
            old_sumFlow = sumFlow;
            sumFlow = 0;

            //if (adjustable)
            //{
            //    if (sumFlow > 0)
            //        pressure += 0.1;
            //    else if (sumFlow < 0)
            //        pressure -= 0.1;
            //    sumFlow = 0;
            //}
        }
    }
}
