using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    class LinkedList<T> : ICollection<T>
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
            //om listan är tom
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

        public void AddLast(T information)
        {
            //om listan är tom
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
                Node<T> n = new Node<T>(information);
                n.setNodeBefore(tail.nodeBefore());
                tail.nodeBefore().setNextNode(n);
                n.setNextNode(tail);
                tail.setNodeBefore(n);
            }
        }

        public void Remove(T information)
        {
            Node<T> search = this.Find(information);
            Node<T> n = head.nextNode();

            while (n != tail)
            {
                if (n == search)
                {

                }
            }

        }

        public void Clear()
        {
            head.setNextNode(null);
            tail.setNodeBefore(null);
            
        }

        public Node<T> Find(T search)
        {
            Node<T> n = head.nextNode();

            while (n != tail)
            {
                if (n.getInfo().Equals(search))
                {
                    return n;
                }
                n = n.nextNode();
                
            }
            return null;
        }

        public bool Contains(T search)
        {
            foreach (var item in this)
            {
                if (item.Equals(search))
                {
                    return true;
                }
            }
            return false;
        }

        public int Count()
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
