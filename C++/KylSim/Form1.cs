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
        Ventil klickad_ventil;
        Ventil[] ventiler = new Ventil[5];
        Ventil v2;
        int count = 0;

        //konstruktor för fönstret
        public Form1() {
            this._canvas = CreateGraphics();
            InitializeComponent();
            n1 = new Nod(5.0, false, "N1", _canvas, 10, 195);
            n2 = new Nod(1.0, true, "N2", _canvas, 120, 195);
            n3 = new Nod(1.0, false, "N3",  _canvas, 240, 195);
            ventiler[0] = new Ventil(10.0, "Ventil1", 80, 200, n1, n2, true, _canvas, this.contextMenuStrip1);
            //v1 = new Ventil(10.0, "Ventil1", 80, 200, n1, n2, true, _canvas, this.contextMenuStrip1);
            ventiler[1] = new Ventil(10.0, "Ventil2", 200, 200, n2, n3, true, _canvas, this.contextMenuStrip1);
            ventiler[2] = new Ventil(10.0, "Ventil3", 200, 100, n2, n3, true, _canvas, this.contextMenuStrip1);
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
            //v1.drawVentil();
            ventiler[0].drawVentil();
            ventiler[1].drawVentil();
            ventiler[2].drawVentil();
        }

        //exekveras en gång i sekunden
        private void Update_Dynamik_Summaflode_Tick(object sender, EventArgs e)
        {
            n1.display();
            n1.dynamik();
            ventiler[0].display();
            ventiler[0].dynamik();
            n2.display();
            n2.dynamik();
            ventiler[1].display();
            ventiler[1].dynamik();
            n3.display();
            n3.dynamik();
            ventiler[2].display();
            ventiler[2].dynamik();
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        //när användaren klickar i fönstret
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            count = 0;
            klickad_ventil = null;
            //kollar om ett klick skedde på en ventil
            while (klickad_ventil == null && ventiler[count] != null)
            {
                klickad_ventil = ventiler[count].menuClick(e.X, e.Y, this);
                count++;
            }
        }

        //när användaren trycker på öppna i menyn
        private void öppnaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.openVentil();
        }

        //när användaren trycker på stäng i menyn
        private void stängToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.closeVentil();
        }
    }
}
