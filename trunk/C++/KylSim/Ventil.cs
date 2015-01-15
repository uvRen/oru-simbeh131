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
    public class Ventil
    {
        //variabler
        private double admittans;
        private string name;
        private string old_str_pos;
        private string old_str_flow;
        private double ventPos;
        private int x;
        private int y;
        private Nod input;
        private Nod output;
        private double flow;
        private bool open;
        private Graphics canvas;
        private ContextMenuStrip menu;

        //konstruktor
        public Ventil(double admittans, string name, int x, int y, Nod input, Nod output, bool open, Graphics canvas, ContextMenuStrip menu)
        {
            this.admittans = admittans;
            this.name = name;
            this.old_str_pos = "";
            this.old_str_flow = "";
            this.x = x;
            this.y = y;
            this.input = input;
            this.output = output;
            this.flow = 0;
            this.open = open;
            this.canvas = canvas;
            this.menu = menu;

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
        }

        //funktioner
        //ritar ut ventilen och dess kopplingar
        public void drawVentil() 
        {
            Pen pen = new Pen(Color.Red);
            //ventilens punkter som ska ritas ut
            Point[] point1 = { new Point(x, y), new Point(x - 18, y + 12), new Point(x - 18, y - 12)};
            Point[] point2 = { new Point(x, y), new Point(x + 18, y + 12), new Point(x + 18, y - 12) };

            //ritar ut två trianglar
            canvas.DrawPolygon(pen, point1);
            canvas.DrawPolygon(pen, point2);

            Pen pen2 = new Pen(Color.Blue);

            //ventilensposition
            Point p1 = new Point(this.x, this.y);

            //input-nodens position
            Point p2 = new Point(input.getX(), input.getY() + 5);
            canvas.DrawLine(pen2, p1, p2);

            //output-nodens position
            p2 = new Point(output.getX(), output.getY() + 5);
            canvas.DrawLine(pen2, p1, p2);

            //skriver ut namnet
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            canvas.DrawString(name, font, brush, (float)x - 20, (float)y - 30);
        }

        //öppnar ventilen
        public void openVentil()
        {
            this.open = true;
            while(ventPos < 0.9)
            {
                this.old_str_pos = ventPos.ToString("0.00");
                ventPos += 0.1;
                //System.Threading.Thread.Sleep(200);
            } 
                
        }

        //stänger ventilen
        public void closeVentil()
        {
            this.open = false;
            while(ventPos > 0.1) 
            {
                this.old_str_pos = ventPos.ToString("0.0");
                ventPos -= 0.1;
                //System.Threading.Thread.Sleep(200);
            } 
        }

        //skriver ut ventilens vpos och flöde
        public void display()
        {
            Brush brush = new SolidBrush(Color.Gainsboro);
            Font font = new Font("Courier", 8);

            //omvandlar ventPos till en string med en decimal
            string value = ventPos.ToString("0.0");
            string info = "vpos: " + value;

            //skriver över det gamla värdet
            canvas.DrawString("vpos: " + old_str_pos, font, brush, (float)x - 25, (float)y + 15);
            canvas.DrawString("flöde: " + old_str_flow, font, brush, (float)x - 25, (float)y + 30);

            //skriver ut info om ventilen
            brush = new SolidBrush(Color.Black);
            canvas.DrawString(info, font, brush, (float)x - 25, (float)y + 15);
            value = flow.ToString("0.0");
            info = "flöde: " + value;
            canvas.DrawString(info, font, brush, (float)x-25, (float)y + 30);

        }

        //beräknar dynamik för ventilen
        public void dynamik()
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

        public Ventil menuClick(int x, int y)
        {
            return this;
        }
    }
}
