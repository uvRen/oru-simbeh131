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

        //Nod n1, n2, n3;
        VVS klickad_ventil;
        //VVS[] komponenter;
        List<VVS> com;
        int count = 0;
        int antal = 0;

        //konstruktor för fönstret
        public Form1() {
            InitializeComponent();
            this._canvas = this.CreateGraphics();

            com = new List<VVS>();
            com.Add(new Nod(5.0, false, "N1", _canvas, 30, 445));
            com.Add(new Nod(1.0, true, "N2", _canvas, 340, 445));
            com.Add(new Nod(2.0, false, "N3", _canvas, 600, 445));
            com.Add(new Nod(1.0, false, "N4", _canvas, 600, 245));
            com.Add(new Nod(2.0, true, "N5", _canvas, 395, 150));
            com.Add(new Nod(1.0, false, "N6", _canvas, 200, 150));
            com.Add(new Pump("Pump1", 450, 430, (Nod)com[1], (Nod)com[2], _canvas, this.contextMenuStrip2));
            com.Add(new Ventil(10.0, "Ventil1", 200, 450, (Nod)com[0], (Nod)com[1], true, _canvas, this.contextMenuStrip1));
            com.Add(new Ventil(10.0, "Ventil2", 400, 250, (Nod)com[3], (Nod)com[5], true, _canvas, this.contextMenuStrip1));
            antal = com.Count;
        }

        //när programmet startar
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            count = 0;
            for (int i = 0; i < com.Count; i++)
            {
                com[count].drawCompenent();
                count++;
            }
            com[4].openComponent();
        }

        //exekveras en gång i sekunden
        private void Update_Dynamik_Summaflode_Tick(object sender, EventArgs e)
        {
            count = 0;
            //while (komponenter[count] != null)
            for (int i = 0; i < com.Count; i++ )
            {
                com[i].display();
                com[i].dynamik();
            }
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        //när användaren klickar i fönstret
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            count = 4;
            klickad_ventil = null;
            //kollar om ett klick skedde på en ventil
            while (count < antal && klickad_ventil == null)
            {
                klickad_ventil = com[count].menuClick(e.X, e.Y, this);
                count++;
            }
        }

        //när användaren trycker på öppna i menyn
        private void öppnaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.openComponent();
        }

        //när användaren trycker på stäng i menyn
        private void stängToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.closeComponent();
        }

        private void startaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.openComponent();
        }

        private void stoppaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.closeComponent();
        }
    }
}
