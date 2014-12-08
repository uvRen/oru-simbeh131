using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    class Program
    {
        public static void Main()
        {
            DataStructures.LinkedList<int> lista = new LinkedList<int>();
            lista.AddFirst(10);
            lista.AddFirst(20);
            lista.AddLast(30);
            lista.AddLast(40);

            lista.RemoveFirst();
            lista.RemoveLast();

            lista.printList();
            Console.Read();
            
        } 
    }
}
