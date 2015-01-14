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
        private Graphics _canvas;

        public Form1() {
            this._canvas = this.CreateGraphics();
            Nod n1 = new Nod(0.0, true, "N1", _canvas, 10, 10);
            n1.writeNod();
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Pen penna = new Pen(Color.Blue);
            _canvas.DrawLine(penna, 0, 0, 640, 480);
        }
    }
}
