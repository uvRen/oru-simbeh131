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
    public class Nod : Form1
    {
        //variabler
        private double pressure;
        private bool adjustable;
        private string name;
        private Graphics canvas;
        private double sumFlow = 0.0;
        private int x;
        private int y;

        //default konstruktor
        public Nod()
        {
            this.pressure = 0.0;
            this.adjustable = false;
            this.name = "";
            this.x = 0;
            this.y = 0;
        }

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

        public void writeNod()
        {
            Pen circle = new Pen(Color.Red);
            canvas.DrawEllipse(circle, x, y, 10, 10);
        }
    }
}
