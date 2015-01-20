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
    public class Vvxl : VVS
    {
        //variabler
        private double admittans;
        private string old_str_flow;
        private double ventPos = 1.0;
        private Nod input;
        private Nod output;
        private double flow;

        //kosntruktor
        public Vvxl(double admittans, string name, int x, int y, Nod input, Nod output, Graphics canvas) : base(name, canvas, x, y)
        {
            this.admittans = admittans;
            this.old_str_flow = "";
            this.input = input;
            this.output = output;
            this.flow = 0;
        }

        public override void drawCompenent()
        {
            //ritar ut filtrer
            Pen pen = new Pen(Color.Red);
            canvas.DrawRectangle(pen, this.x, this.y, 20, 40);

            //ritar upp kopplingarna till noderna
            pen = new Pen(Color.Blue);

            Point p1 = new Point(this.x+10, this.y);
            Point p2 = new Point(output.getX()+5, output.getY());
            Point p3 = new Point(input.getX()+5, input.getY());

            canvas.DrawLine(pen, p1, p2);
            canvas.DrawLine(pen, p1, p3);

            //skriver ut namnet
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            canvas.DrawString(name, font, brush, (float)x+30, (float)y +10);

        }

        //beräknar dynamik för ventilen
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

        public override void display()
        {
            Brush brush = new SolidBrush(Color.Gainsboro);
            Font font = new Font("Courier", 8);

            //omvandlar ventPos till en string med en decimal
            string value = flow.ToString("0.0");
            string info = "";

            //skriver över det gamla värdet
            canvas.DrawString("flöde: " + old_str_flow, font, brush, (float)x +30, (float)y + 30);

            //skriver ut info om ventilen
            brush = new SolidBrush(Color.Black);
            info = "flöde: " + value;
            canvas.DrawString(info, font, brush, (float)x +30, (float)y + 30);

        }
    }
}
