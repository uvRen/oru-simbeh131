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
    public class VVS
    {
        protected string name;
        protected Graphics canvas;
        protected ContextMenuStrip menu;
        protected int x;
        protected int y;

        /// <summary>
        /// Default konstruktor för VVS
        /// </summary>
        public VVS()
        {
            this.name = "";
            this.canvas = null;
            this.menu = null;
            this.x = -1;
            this.y = -1;
        }

        /// <summary>
        /// Konstruktor med parametrar
        /// </summary>
        /// <param name="name"></param>
        /// <param name="canvas"></param>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="menu"></param>
        public VVS(string name, Graphics canvas, int x, int y, ContextMenuStrip menu = null)
        {
            this.name = name;
            this.canvas = canvas;
            this.menu = menu;
            this.x = x;
            this.y = y;
        }

        /// <summary>
        /// Returnerar x-koordinaten
        /// </summary>
        /// <returns>X</returns>
        public int getX()
        {
            return this.x;
        }

        /// <summary>
        /// Returnerar y-koordinaten
        /// </summary>
        /// <returns>Y</returns>
        public int getY()
        {
            return this.y;
        }

        /// <summary>
        /// Ritar ut komponent
        /// </summary>
        public virtual void drawCompenent() { }
        /// <summary>
        /// Skriver ut information om komponenter
        /// </summary>
        public virtual void display() { }
        /// <summary>
        /// Beräknare flöde och tryck för komponenter
        /// </summary>
        public virtual void dynamik() { }
        /// <summary>
        /// Öppnar komponent
        /// </summary>
        public virtual void openComponent() { }
        /// <summary>
        /// Stänger komponent
        /// </summary>
        public virtual void closeComponent() { }
        /// <summary>
        /// Ger trycket i komponenten
        /// </summary>
        /// <returns>Trycket</returns>
        public virtual double getPressure()
        {
            return 0.0;
        }
        /// <summary>
        /// Ändrar flödet förbi en nod
        /// </summary>
        /// <param name="flow"></param>
        public virtual void add_summaflode(double flow) { }
        /// <summary>
        /// Tar reda på vilken komponent som ska visa menyn
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="fonster"></param>
        /// <returns>En komponent</returns>
        public virtual VVS menuClick(int x, int y, Control fonster)
        {
            return this;
        }
    }
}
