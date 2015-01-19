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
    public class VVS
    {
        protected string name;
        protected Graphics canvas;
        protected ContextMenuStrip menu;
        protected int x;
        protected int y;

        public VVS()
        {
            this.name = "";
            this.canvas = null;
            this.menu = null;
            this.x = -1;
            this.y = -1;
        }

        public VVS(string name, Graphics canvas, int x, int y, ContextMenuStrip menu = null) 
        {
            this.name = name;
            this.canvas = canvas;
            this.menu = menu;
            this.x = x;
            this.y = y;
        }

        public int getX()
        {
            return this.x;
        }

        public int getY()
        {
            return this.y;
        }

        public virtual void drawCompenent() {}
        public virtual void display() {}
        public virtual void dynamik() {}
        public virtual void openVentil() { }
        public virtual void closeVentil() { }
        public virtual double getPressure() {
            return 0.0;
        }
        public virtual void add_summaflode(double flow) { }
        public virtual VVS menuClick(int x, int y, Control fonster)
        {
            return this;
        }
    }
}
