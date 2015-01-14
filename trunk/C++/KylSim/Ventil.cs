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
    public class Ventil
    {
        //variabler
        private double admittans;
        private string name;
        private Point p;
        private int x;
        private int y;
        private Nod input;
        private Nod output;
        private double flow;
        private bool open;
        private Graphics canvas;

        //konstruktor
        public Ventil(double admittans, string name, int xp, int yp, int x, int y, Nod input, Nod output, bool open, Graphics canvas)
        {
            this.admittans = admittans;
            this.name = name;
            this.p.X = xp;
            this.p.Y = yp;
            this.x = x;
            this.y = y;
            this.input = input;
            this.output = output;
            this.flow = 0;
            this.open = open;
            this.canvas = canvas;
        }

        //funktioner
        //ritar ut ventilen och dess kopplingar
        public void drawVentil() 
        {
            Pen pen = new Pen(Color.Red);
            Point[] point1 = { new Point(x, y), new Point(x - 18, y + 12), new Point(x - 18, y - 12)};
            Point[] point2 = { new Point(x, y), new Point(x + 18, y + 12), new Point(x + 18, y - 12) };

            //ritar ut två trianglar
            canvas.DrawPolygon(pen, point1);
            canvas.DrawPolygon(pen, point2);

            Pen pen2 = new Pen(Color.Blue);
            Point p2 = new Point(input.getX(), input.getY() + 5);
            canvas.DrawLine(pen2, p, p2);
            p2 = new Point(output.getX(), output.getY() + 5);
            canvas.DrawLine(pen2, p, p2);
        }
    }
}
