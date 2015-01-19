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
        int antal = 5;

        //konstruktor för fönstret
        public Form1() {
            this._canvas = CreateGraphics();
            InitializeComponent();

            com = new List<VVS>();
            com.Add(new Nod(5.0, false, "N1", _canvas, 10, 195));
            com.Add(new Nod(1.0, true, "N2", _canvas, 120, 195));
            com.Add(new Nod(3.0, false, "N3", _canvas, 240, 195));
            com.Add(new Ventil(10.0, "Ventil1", 80, 200, (Nod)com[0], (Nod)com[1], true, _canvas, this.contextMenuStrip1));
            com.Add(new Ventil(10.0, "Ventil2", 200, 200, (Nod)com[1], (Nod)com[2], true, _canvas, this.contextMenuStrip1));
            com.Add(new Pump("Pump1", 60, 60, (Nod)com[0], (Nod)com[1], _canvas, this.contextMenuStrip1));
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
            count = 3;
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
            klickad_ventil.openVentil();
        }

        //när användaren trycker på stäng i menyn
        private void stängToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.closeVentil();
        }
    }
}
