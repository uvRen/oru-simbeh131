﻿using System;
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
    public class Ventil : VVS
    {
        private double admittans;
        private string old_str_pos;
        private string old_str_flow;
        private double ventPos;
        private Nod input;
        private Nod output;
        private double flow;
        private bool open;

        /// <summary>
        /// Konstruktor med parametrar
        /// </summary>
        /// <param name="admittans"></param>
        /// <param name="name"></param>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="input"></param>
        /// <param name="output"></param>
        /// <param name="open"></param>
        /// <param name="canvas"></param>
        /// <param name="menu"></param>
        public Ventil(double admittans, string name, int x, int y, Nod input, Nod output, bool open, Graphics canvas, ContextMenuStrip menu)
            : base(name, canvas, x, y, menu)
        {
            this.admittans = admittans;
            this.old_str_flow = "";
            this.input = input;
            this.output = output;
            this.flow = 0;
            this.open = open;

            //om ventilen är öppen
            if (open)
            {
                this.ventPos = 1.0;
            }
            //om ventilen är stängd
            else
            {
                this.ventPos = 0.0;
            }

            this.old_str_pos = ventPos.ToString("0.0");
        }

        /// <summary>
        /// Ritar ut ventilen och kopplingar till närliggande komponenter och ventilens namn
        /// </summary>
        public override void drawCompenent()
        {
            Pen pen = new Pen(Color.Red);
            //ventilens punkter som ska ritas ut
            Point[] point1 = { new Point(x, y), new Point(x - 18, y + 12), new Point(x - 18, y - 12) };
            Point[] point2 = { new Point(x, y), new Point(x + 18, y + 12), new Point(x + 18, y - 12) };

            //ritar ut två trianglar
            canvas.DrawPolygon(pen, point1);
            canvas.DrawPolygon(pen, point2);

            Pen pen2 = new Pen(Color.Blue);

            //ventilensposition
            Point p1 = new Point(this.x, this.y);

            //input-nodens position
            Point p2 = new Point(input.getX(), input.getY() + 5);

            ////output-nodens position
            Point p3 = new Point(output.getX(), output.getY() + 5);

            Point temp;
            Point nod;

            //rita till output-noden
            if (p3.Y != p1.Y)
            {
                temp = new Point(p3.X + 5, p1.Y);
                nod = new Point(p3.X + 5, p3.Y);
                canvas.DrawLine(pen2, p1, temp);
                canvas.DrawLine(pen2, temp, nod);
            }
            else
            {
                canvas.DrawLine(pen2, p1, p3);
            }
            //rita till output-noden
            if (p2.Y != p1.Y)
            {
                temp = new Point(p2.X + 5, p1.Y);
                nod = new Point(p2.X + 5, p2.Y);
                canvas.DrawLine(pen2, p1, temp);
                canvas.DrawLine(pen2, temp, nod);
            }
            else
            {
                canvas.DrawLine(pen2, p1, p2);
            }

            ////skriver ut namnet
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            canvas.DrawString(name, font, brush, (float)x - 20, (float)y - 30);
        }

        /// <summary>
        /// Öppnar ventilen
        /// </summary>
        public override void openComponent()
        {
            this.open = true;
        }

        /// <summary>
        /// Stänger ventilen
        /// </summary>
        public override void closeComponent()
        {
            this.open = false;
        }

        /// <summary>
        /// Skriver ut ventilkäglans position och flödet i ventilen
        /// </summary>
        public override void display()
        {
            //stänger eller öppnar ventilen successivt
            if (this.ventPos > 0.1 && this.open == false)
            {
                this.old_str_pos = "vpos: " + ventPos.ToString("0.0");
                ventPos -= 0.1;
            }
            else if (this.ventPos < 1.0 && this.open == true)
            {
                this.old_str_pos = "vpos: " + ventPos.ToString("0.0");
                ventPos += 0.1;
            }
            Brush brush = new SolidBrush(Color.Gainsboro);
            Font font = new Font("Courier", 8);

            //omvandlar ventPos till en string med en decimal
            string value = ventPos.ToString("0.0");
            string info = "vpos: " + ventPos;

            //skriver över det gamla värdet
            canvas.DrawString("vpos: " + old_str_pos, font, brush, (float)x - 25, (float)y + 15);
            canvas.DrawString("flöde: " + old_str_flow, font, brush, (float)x - 25, (float)y + 30);

            //skriver ut info om ventilen
            brush = new SolidBrush(Color.Black);
            canvas.DrawString(info, font, brush, (float)x - 25, (float)y + 15);
            value = flow.ToString("0.0");
            info = "flöde: " + value;
            canvas.DrawString(info, font, brush, (float)x - 25, (float)y + 30);

        }

        /// <summary>
        /// Beräknar flödet i ventilen
        /// </summary>
        public override void dynamik()
        {
            //anger det gamla flow-värdet till strängen old_flow
            this.old_str_flow = this.flow.ToString("0.0");
            //hämtar trycket från noderna
            double inNodPressure, outNodPressure;
            inNodPressure = this.input.getPressure();
            outNodPressure = this.output.getPressure();

            double calc = 0;

            if (inNodPressure >= outNodPressure)
            {
                calc = this.admittans * ventPos * (Math.Sqrt(inNodPressure - outNodPressure));
                this.flow = calc;
            }

            else
            {
                calc = -1 * this.admittans * ventPos * (Math.Sqrt(outNodPressure - inNodPressure));
                this.flow = calc;
            }

            //skickar flödet till in-noden
            input.add_summaflode(-flow);
            //skickar flödet till ut-noden
            output.add_summaflode(flow);
        }

        /// <summary>
        /// Kollar om ventilen har blivit tryckt på och ska visa menyn eller inte
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="fonster"></param>
        /// <returns>Komponent</returns>
        public override VVS menuClick(int x, int y, Control fonster)
        {
            //kollar om x-koordinaten stämmer överens med ventilen
            if (x >= (this.x - 18) && x <= (this.x + 18))
            {
                //kollar om y-koordinaten stämmer överens med ventilen
                if (y >= (this.y - 12) && y <= (this.y + 12))
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
