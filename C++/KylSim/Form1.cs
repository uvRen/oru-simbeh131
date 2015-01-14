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
    public partial class Form1 : Form {
        Graphics _canvas;
        Nod n1, n2, n3;

        public Form1() {
            this._canvas = CreateGraphics();
            InitializeComponent();
            n1 = new Nod(0.0, true, "N1", _canvas, 200, 100);
            n2 = new Nod(1.0, true, "N2", _canvas, 100, 200);
            n3 = new Nod(2.0, true, "N3",  _canvas, 200, 20);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            n1.writeNod();
            n2.writeNod();
            n3.writeNod();
            n1.display();
            n2.display();
            n3.display();

        }

        private void Update_Dynamik_Summaflode_Tick(object sender, EventArgs e)
        {
            n1.display();
            n1.dynamik();
            n2.display();
            n2.dynamik();
            n3.display();
            n3.dynamik();
        }
    }
}
