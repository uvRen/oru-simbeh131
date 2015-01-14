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
            _canvas = CreateGraphics();
            //Nod n4 = new Nod(0.0, true, "N1", _canvas, 10, 10);
            //this.n2 = new Nod(0.0, true, "N1", _canvas, 10, 10);
            //n2 = new Nod(0.0, true, "N2", _canvas, 40, 10);
            //n3 = new Nod(0.0, true, "N3", _canvas, 80, 10);
            //Nod n1 = new Nod(0.0, true, "N1", _canvas, 20, 20);
            //n1.writeNod();
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e) {
            Pen pen = new Pen(Color.Black);
            _canvas.DrawLine(pen, 20, 20, 100, 100);

            n1 = new Nod(0.0, true, "N1", _canvas, 20, 20);
            n1.writeNod();
            //n2.writeNod();
            //n3.writeNod();
            //n1.display();
            //n2.display();
            //n3.display();
        }
    }
}
