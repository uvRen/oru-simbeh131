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
        VVS klickad_ventil;
        VVS[] komponenter = new VVS[20];
        int count = 0;
        int antal = 6;

        //konstruktor för fönstret
        public Form1() {
            this._canvas = CreateGraphics();
            InitializeComponent();
            //n1 = new Nod(5.0, false, "N1", _canvas, 10, 195);
            //n2 = new Nod(1.0, true, "N2", _canvas, 120, 195);
            //n3 = new Nod(1.0, false, "N3",  _canvas, 240, 195);
            //v1 = new Ventil(10.0, "Ventil1", 80, 200, n1, n2, true, _canvas, this.contextMenuStrip1);
            
            komponenter[0] = new Nod(5.0, false, "N1", _canvas, 10, 195);
            komponenter[1] = new Nod(1.0, true, "N2", _canvas, 120, 195);
            komponenter[2] = new Nod(1.0, false, "N3",  _canvas, 240, 195);
            komponenter[3] = new Ventil(10.0, "Ventil1", 80, 200, komponenter[0], komponenter[1], true, _canvas, this.contextMenuStrip1);
            komponenter[4] = new Ventil(10.0, "Ventil2", 200, 200, komponenter[1], komponenter[2], true, _canvas, this.contextMenuStrip1);
            komponenter[5] = new Ventil(10.0, "Ventil3", 200, 100, komponenter[1], komponenter[2], true, _canvas, this.contextMenuStrip1);
        }

        //när programmet startar
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            count = 0;
            //while (komponenter[count] != null)
            while (count < antal)
            {
                komponenter[count].drawCompenent();
                count++;
            }
            //n1.drawCompenent();
            //n2.drawCompenent();
            //n3.drawCompenent();
            //n1.display();
            //n2.display();
            //n3.display();
            ////v1.drawVentil();
            //komponenter[0].drawCompenent();
            //komponenter[1].drawCompenent();
            //komponenter[2].drawCompenent();
        }

        //exekveras en gång i sekunden
        private void Update_Dynamik_Summaflode_Tick(object sender, EventArgs e)
        {
            count = 0;
            //while (komponenter[count] != null)
            while (count < antal)
            {
                komponenter[count].display();
                komponenter[count].dynamik();
                count++;
            }
            //n1.display();
            //n1.dynamik();
            //komponenter[0].display();
            //komponenter[0].dynamik();
            //n2.display();
            //n2.dynamik();
            //komponenter[1].display();
            //komponenter[1].dynamik();
            //n3.display();
            //n3.dynamik();
            //komponenter[2].display();
            //komponenter[2].dynamik();
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
            //while (klickad_ventil == null && komponenter[count] != null)
            while (count < antal && klickad_ventil == null)
            {
                klickad_ventil = komponenter[count].menuClick(e.X, e.Y, this);
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
