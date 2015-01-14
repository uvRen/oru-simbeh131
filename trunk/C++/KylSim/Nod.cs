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
    public class Nod
    {
        //variabler
        private double pressure;
        private bool adjustable;
        private string name;
        private Graphics canvas;
        private double sumFlow = 0.0;
        private int x;
        private int y;
        private double inFlow = 0.0;
        private double outFlow = 0.0;

        //konstruktor med parametrar
        public Nod(double pressure, bool adjustable, string name, Graphics canvas, int x, int y)
        {
            this.pressure = pressure;
            this.adjustable = adjustable;
            this.name = name;
            this.canvas = canvas;
            this.x = x;
            this.y = y;
        }

        //funktioner
        //returnerar trycket
        public double getPressure()
        {
            return this.pressure;
        }

        //returner x-koordinaten
        public int getX()
        {
            return x;
        }

        //returnerar y-koordinaten
        public int getY()
        {
            return y;
        }

        //ritar ut nodemn samt nodens namn
        public void drawNod()
        {
            Pen circle = new Pen(Color.Red);
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            //ritar ut cirkeln
            canvas.DrawEllipse(circle, x, y, 10, 10);
            //skriver ut namnet på noden
            canvas.DrawString(name, font, brush, (float)x, (float)y-15);
        }

        //skriver ut trycket i noden
        public void display()
        {
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            string tryck = "Tryck: " + pressure;
            canvas.DrawString(tryck, font, brush, (float)x, (float)y + 15);
        }

        //ändar inflödet till noden
        public void add_summaflode(double flow)
        {
            this.inFlow = flow;
        }

        //reglerar trycket
        public void dynamik()
        {
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
