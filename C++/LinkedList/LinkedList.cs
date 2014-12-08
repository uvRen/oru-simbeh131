using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    class LinkedList<T>
    {
        private Node<T> head;
        private Node<T> tail;

        //konstruktor
        public LinkedList()
        {
            head = new Node<T>();
            tail = new Node<T>();
        }

        //funktioner
        public void AddFirst(T information)
        {
            if (head.nextNode() == null)
            {
                Node<T> n = new Node<T>(information);
                head.setNextNode(n);
                n.setNodeBefore(head);
                n.setNextNode(tail);
                tail.setNodeBefore(n);
            }
            else
            {
                Node<T> ny = new Node<T>(information);
                ny.setNextNode(head.nextNode());
                head.nextNode().setNodeBefore(ny);
                head.setNextNode(ny);
                ny.setNodeBefore(head);
            }
        }

        public int count()
        {
            Node<T> n = head.nextNode();
            int antal = 0;
            while (n != tail)
            {
                antal++;
                n = n.nextNode();
            }
            return antal;
        }

        public Node<T> First() {
            return head.nextNode();
        }

        public Node<T> Last()
        {
            return tail.nodeBefore();
        }

        public void printList()
        {
            Node<T> n = head.nextNode();

            while (n != tail)
            {
                Console.WriteLine(n.getInfo());
                n = n.nextNode();
            }
        }
    }
}
