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
        Ventil v1;

        //konstruktor för fönstret
        public Form1() {
            this._canvas = CreateGraphics();
            InitializeComponent();
            n1 = new Nod(0.0, true, "N1", _canvas, 50, 195);
            n2 = new Nod(1.0, true, "N2", _canvas, 300, 195);
            n3 = new Nod(2.0, true, "N3",  _canvas, 200, 20);
            v1 = new Ventil(10.0, "Ventil1", 200, 200, 200, 200, n1, n2, true, _canvas);
        }

        //när programmet startar
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            n1.drawNod();
            n2.drawNod();
            n3.drawNod();
            n1.display();
            n2.display();
            n3.display();
            v1.drawVentil();

        }

        //exekveras en gång i sekunden
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
