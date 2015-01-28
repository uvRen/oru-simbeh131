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
    public class Pump : VVS
    {
        private double flow;
        private double varv;
        private bool open;
        private string old_str_pos = "speed: 0.0";
        private string old_str_flow;
        private Nod input;
        private Nod output;
        private double a;
        private double b;

        /// <summary>
        /// Konstroktor med parametrar
        /// </summary>
        /// <param name="name"></param>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="input"></param>
        /// <param name="output"></param>
        /// <param name="canvas"></param>
        /// <param name="menu"></param>
        public Pump(string name, int x, int y, Nod input, Nod output, Graphics canvas, ContextMenuStrip menu)
            : base(name, canvas, x, y, menu)
        {
            this.input = input;
            this.output = output;
            a = 5.0;
            b = 10.0;
            varv = 0.0;
            flow = 0.0;
            open = false;
        }

        /// <summary>
        /// Beräknar flödet
        /// </summary>
        public override void dynamik()
        {
            this.old_str_flow = this.flow.ToString("0.0");
            //k begränsar flödet
            double k = input.getPressure();
            if (k > 1.0)
            {
                k = 1.0;
            }

            double calc = 0;
            double inPressure, outPressure;
            inPressure = input.getPressure();
            outPressure = output.getPressure();

            if (inPressure >= outPressure)
            {
                calc = k * varv * a * (b + (Math.Sqrt(inPressure - outPressure)));
            }
            else
            {
                calc = k * varv * a * (b - (Math.Sqrt(outPressure - inPressure)));
            }

            this.flow = calc;

            //skickar flödet till in-noden
            input.add_summaflode(-flow);
            //skickar flödet till ut-noden
            output.add_summaflode(flow);
        }

        /// <summary>
        /// Ritar ut pumpen, kopplingar till närliggande komponenter och pumpens namn
        /// </summary>
        public override void drawCompenent()
        {
            Pen circle = new Pen(Color.Red);
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            //ritar ut cirkeln
            canvas.DrawEllipse(circle, (float)x, (float)y, 40, 40);
            //skriver ut namnet på pumpen
            canvas.DrawString(name, font, brush, (float)x, (float)y - 20);


            //ritar ut kopplingar till nästliggande noder
            Pen pen2 = new Pen(Color.Blue);
            //ventilensposition
            Point p1 = new Point(this.x + 20, this.y + 20);

            //input-nodens position
            Point p2 = new Point(input.getX(), input.getY() + 5);
            canvas.DrawLine(pen2, p1, p2);

            //output-nodens position
            p2 = new Point(output.getX(), output.getY() + 5);
            canvas.DrawLine(pen2, p1, p2);
        }

        /// <summary>
        /// Skriver ut flödet och varvtalet i pumpen
        /// </summary>
        public override void display()
        {
            //stänger eller öppnar pumpen successivt
            if (this.varv > 0.1 && this.open == false)
            {
                this.old_str_pos = varv.ToString("0.0");
                varv -= 0.1;
            }
            else if (this.varv < 0.9 && this.open == true)
            {
                this.old_str_pos = varv.ToString("0.00");
                varv += 0.1;
            }

            Brush brush = new SolidBrush(Color.Gainsboro);
            Font font = new Font("Courier", 8);

            //omvandlar ventPos till en string med en decimal
            string value = varv.ToString("0.0");
            string info = "speed: " + value;

            //skriver över det gamla värdet
            canvas.DrawString("speed: " + old_str_pos, font, brush, (float)x + 3, (float)y + 40);
            canvas.DrawString("flöde: " + old_str_flow, font, brush, (float)x + 3, (float)y + 55);

            //skriver ut info om ventilen
            brush = new SolidBrush(Color.Black);
            canvas.DrawString(info, font, brush, (float)x + 3, (float)y + 40);
            value = flow.ToString("0.0");
            info = "flöde: " + value;
            canvas.DrawString(info, font, brush, (float)x + 3, (float)y + 55);
        }

        /// <summary>
        /// Startar pumpen
        /// </summary>
        public override void openComponent()
        {
            this.open = true;
        }

        /// <summary>
        /// Stänger pumpen
        /// </summary>
        public override void closeComponent()
        {
            this.open = false;
        }

        /// <summary>
        /// Kollar om pumpen har blivit tryckt på och ska visa menyn eller inte
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="fonster"></param>
        /// <returns>Komponent</returns>
        public override VVS menuClick(int x, int y, Control fonster)
        {
            //kollar om x-koordinaten stämmer överens med pumpen
            if (x >= this.x && x <= (this.x + 40))
            {
                //kollar om y-koordinaten stämmer överens med pumpen
                if (y >= (this.y - 20) && y <= (this.y + 20))
                {
                    Point p = new Point(x, y);
                    menu.Show(fonster, p);
                    return this;
                }
            }
            return null;
        }
    }
}
