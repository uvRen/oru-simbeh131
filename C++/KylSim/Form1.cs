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
        Ventil v1, v2;
        int count = 0;

        //konstruktor för fönstret
        public Form1() {
            this._canvas = CreateGraphics();
            InitializeComponent();
            n1 = new Nod(5.0, false, "N1", _canvas, 10, 195);
            n2 = new Nod(1.0, true, "N2", _canvas, 120, 195);
            n3 = new Nod(1.0, false, "N3",  _canvas, 240, 195);
            v1 = new Ventil(10.0, "Ventil1", 80, 200, n1, n2, true, _canvas, this.ContextMenuStrip);
            v2 = new Ventil(10.0, "Ventil2", 200, 200, n2, n3, true, _canvas, this.ContextMenuStrip);
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
            v2.drawVentil();
        }

        //exekveras en gång i sekunden
        private void Update_Dynamik_Summaflode_Tick(object sender, EventArgs e)
        {
            n1.display();
            n1.dynamik();
            v1.display();
            v1.dynamik();
            n2.display();
            n2.dynamik();
            v2.display();
            v2.dynamik();
            n3.display();
            n3.dynamik();
            if (count < 1)
            {
                v2.closeVentil();
                count++;
            }
            
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        private void contextMenuStrip1_MouseDown(object sender, MouseEventArgs e)
        {
            v1.menuClick(e.X, e.Y, this);
        }
    }
}
