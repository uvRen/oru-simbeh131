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
    public partial class Form1 : Form
    {
        Graphics _canvas;
        VVS klickad_ventil;
        List<VVS> com;
        int count = 0;
        int antal = 0;

        /// <summary>
        /// Konstruktor för det grafiska fönstret
        /// </summary>
        public Form1()
        {
            InitializeComponent();
            this._canvas = this.CreateGraphics();

            com = new List<VVS>();
            com.Add(new Nod(2.0, false, "N1", _canvas, 30, 445));
            com.Add(new Nod(0.0, true, "N2", _canvas, 340, 445));
            com.Add(new Nod(0.0, true, "N3", _canvas, 600, 445));
            com.Add(new Nod(0.0, true, "N4", _canvas, 600, 245));
            com.Add(new Nod(0.0, true, "N5", _canvas, 395, 145));
            com.Add(new Nod(0.0, true, "N6", _canvas, 200, 145));
            com.Add(new Nod(2.0, false, "N7", _canvas, 30, 145));
            com.Add(new Nod(1.0, false, "N8", _canvas, 650, 60));
            com.Add(new Filter(10, "Filter1", 300, 140, (Nod)com[4], (Nod)com[5], _canvas));
            com.Add(new Vvxl(10, "VVXL", 595, 325, (Nod)com[2], (Nod)com[3], _canvas));
            com.Add(new Pump("Pump1", 450, 430, (Nod)com[1], (Nod)com[2], _canvas, this.contextMenuStrip2));
            com.Add(new Ventil(10.0, "Ventil1", 200, 450, (Nod)com[0], (Nod)com[1], true, _canvas, this.contextMenuStrip1));
            com.Add(new Ventil(10.0, "Ventil2", 500, 150, (Nod)com[3], (Nod)com[4], true, _canvas, this.contextMenuStrip1));
            com.Add(new Ventil(10.0, "Ventil3", 120, 150, (Nod)com[5], (Nod)com[6], true, _canvas, this.contextMenuStrip1));
            com.Add(new Ventil(10.0, "Ventil4", 400, 250, (Nod)com[3], (Nod)com[5], false, _canvas, this.contextMenuStrip1));
            com.Add(new Ventil(10.0, "Ventil5", 530, 65, (Nod)com[4], (Nod)com[7], false, _canvas, this.contextMenuStrip1));
            antal = com.Count;
        }

        /// <summary>
        /// Funktionen körs när programmet startas och ritar då ut alla komponenter
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
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

        /// <summary>
        /// Funktionen ett antal gånger i sekunden enligt en bestämd klockfrekvens
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Update_Dynamik_Summaflode_Tick(object sender, EventArgs e)
        {
            count = 0;
            for (int i = 0; i < com.Count; i++)
            {
                com[i].dynamik();
                com[i].display();
            }
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        /// <summary>
        /// När ett musklick uppfattas i fönstret
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            count = 10;
            klickad_ventil = null;
            //kollar om ett klick skedde på en ventil
            while (count < antal && klickad_ventil == null)
            {
                klickad_ventil = com[count].menuClick(e.X, e.Y, this);
                count++;
            }
        }

        /// <summary>
        /// Vid klick på "Öppna" i ventilens meny
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void öppnaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.openComponent();
        }

        /// <summary>
        /// Vid klick på "Stäng" i ventilens meny
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void stängToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.closeComponent();
        }

        /// <summary>
        /// Vid klick på "Starta" i pumpens meny
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void startaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.openComponent();
        }

        /// <summary>
        /// Vid klick på "Stoppa" i pumpens meny
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void stoppaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            klickad_ventil.closeComponent();
        }
    }
}
