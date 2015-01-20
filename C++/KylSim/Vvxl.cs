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
    public class Vvxl : VVS
    {
        //variabler
        private double admittans;
        private string old_str_pos;
        private string old_str_flow;
        private double ventPos;
        private Nod input;
        private Nod output;
        private double flow;
        private bool open;
        private double ventPos = 1.0;

        public Vvxl(double admittans, string name, int x, int y, Nod input, Nod output, Graphics canvas) : base(name, canvas, x, y)
        {
            this.admittans = admittans;
            this.old_str_flow = "";
            this.input = input;
            this.output = output;
            this.flow = 0;
        }
    }
}
