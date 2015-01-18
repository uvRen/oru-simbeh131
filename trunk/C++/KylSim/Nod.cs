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
        //private string name;
        private string old_str;
        //private Graphics canvas;
        private double sumFlow = 0.0;
        //private int x;
        //private int y;
        private double inFlow = 0.0;
        private double outFlow = 0.0;

        //konstruktor med parametrar
        public Nod(double pressure, bool adjustable, string name, Graphics canvas, int x, int y) : base(name, canvas, x, y)
        {
            this.pressure = pressure;
            this.adjustable = adjustable;
            this.old_str = "";
        }

        //funktioner
        //returnerar trycket
        public override double getPressure()
        {
            return this.pressure;
        }

        ////returner x-koordinaten
        //public int getX()
        //{
        //    return x;
        //}

        ////returnerar y-koordinaten
        //public int getY()
        //{
        //    return y;
        //}

        //ritar ut nodemn samt nodens namn
        public override void drawCompenent()
        {
            Pen circle = new Pen(Color.Red);
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            //ritar ut cirkeln
            canvas.DrawEllipse(circle, (float)x, (float)y, 10, 10);
            //skriver ut namnet på noden
            canvas.DrawString(name, font, brush, (float)x, (float)y-15);
        }

        //skriver ut trycket i noden
        public override void display()
        {
            Brush brush = new SolidBrush(Color.Gainsboro);
            Font font = new Font("Courier", 8);
            //skriver över det gamla värdet
            string value = "Tryck: " + old_str;
            canvas.DrawString(value, font, brush, (float)x, (float)y + 15);

            //skriver ut det nya värdet
            brush = new SolidBrush(Color.Black);
            value = "Tryck: " + pressure;
            canvas.DrawString(value, font, brush, (float)x, (float)y + 15);
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
            if (adjustable)
            {
                if (sumFlow > 0)
                    pressure += 0.1;
                else if (sumFlow < 0)
                    pressure -= 0.1;
                sumFlow = 0;
            }
        }
    }
}
