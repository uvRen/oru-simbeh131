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
    public class Filter : VVS
    {
        private double admittans;
        private string old_str_pos;
        private string old_str_flow;
        private double ventPos;
        private Nod input;
        private Nod output;
        private double flow;
        private int countRensa = 0;

        /// <summary>
        /// Konstruktor med parametrar
        /// </summary>
        /// <param name="admittans"></param>
        /// <param name="name"></param>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <param name="input"></param>
        /// <param name="output"></param>
        /// <param name="canvas"></param>
        public Filter(double admittans, string name, int x, int y, Nod input, Nod output, Graphics canvas)
            : base(name, canvas, x, y)
        {
            this.admittans = admittans;
            this.input = input;
            this.output = output;
            ventPos = 1.0;
        }

        /// <summary>
        /// Beräknare flödet i filtret
        /// </summary>
        public override void dynamik()
        {
            //filtret blir igensatt
            if (flow > 0.0)
            {
                this.old_str_pos = ventPos.ToString("0.0");
                ventPos = ventPos - (0.0001 * flow);
            }
            //filtret spolas rent
            else
            {
                this.old_str_pos = ventPos.ToString("0.0");
                ventPos = ventPos + (0.01 * flow);
            }
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
        /// Skriver ut filteröppningen och fldöet
        /// </summary>
        public override void display()
        {
            Brush brush = new SolidBrush(Color.Gainsboro);
            Font font = new Font("Courier", 8);

            //omvandlar ventPos till en string med en decimal
            string value = ventPos.ToString("0.0");
            string info = "vpos: " + value;

            //skriver över det gamla värdet
            canvas.DrawString("vpos: " + old_str_pos, font, brush, (float)x, (float)y + 25);
            canvas.DrawString("flöde: " + old_str_flow, font, brush, (float)x, (float)y + 40);

            //skriver ut info om ventilen
            brush = new SolidBrush(Color.Black);
            canvas.DrawString(info, font, brush, (float)x, (float)y + 25);
            value = flow.ToString("0.0");
            info = "flöde: " + value;
            canvas.DrawString(info, font, brush, (float)x, (float)y + 40);

            if (ventPos < 0.5 && countRensa % 2 == 0)
            {
                brush = new SolidBrush(Color.Red);
                canvas.DrawString("Rensa", font, brush, (float)x, (float)y - 35);
            }
            else
            {
                brush = new SolidBrush(Color.Gainsboro);
                canvas.DrawString("Rensa", font, brush, (float)x, (float)y - 35);
                canvas.DrawString("Rensa", font, brush, (float)x, (float)y - 35);
                canvas.DrawString("Rensa", font, brush, (float)x, (float)y - 35);
            }
            this.countRensa = this.countRensa + 1;
        }

        /// <summary>
        /// Ritar ut filtret, kopplingar till närliggande komponenter och filtrets namn
        /// </summary>
        public override void drawCompenent()
        {
            //ritar ut filtrer
            Pen pen = new Pen(Color.Red);
            canvas.DrawRectangle(pen, this.x, this.y, 30, 20);

            //ritar ut linjerna i filtret
            canvas.DrawLine(pen, (float)x + 5, (float)y, (float)x + 5, (float)y + 15);
            canvas.DrawLine(pen, (float)x + 25, (float)y, (float)x + 25, (float)y + 15);
            canvas.DrawLine(pen, (float)x + 15, (float)y + 5, (float)x + 15, (float)y + 20);

            //ritar upp kopplingarna till noderna
            pen = new Pen(Color.Blue);

            Point p1 = new Point(this.x, this.y + 10);
            Point p2 = new Point(output.getX(), output.getY() + 5);
            Point p3 = new Point(input.getX(), input.getY() + 5);

            canvas.DrawLine(pen, p1, p2);
            canvas.DrawLine(pen, p1, p3);

            //skriver ut namnet
            Brush brush = new SolidBrush(Color.Black);
            Font font = new Font("Courier", 8);
            canvas.DrawString(name, font, brush, (float)x, (float)y - 20);

        }
    }
}
