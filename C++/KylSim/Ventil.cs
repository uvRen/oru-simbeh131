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

        public Ventil(double admittans, string name, int xp, int yp, int x, int y, Nod input, Nod output, double flow, bool open)
        {
            this.admittans = admittans;
            this.name = name;
            this.p.X = xp;
            this.p.Y = yp;
            this.x = x;
            this.y = y;
            this.input = input;
            this.output = output;
            this.flow = flow;
            this.open = open;
        }

        public void drawVentil() 
        {

        }
    }
}
