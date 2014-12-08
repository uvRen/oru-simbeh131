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

        #region Metoder
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

        public void RemoveFirst()
        {
            head.nextNode().nextNode().setNodeBefore(head);
            head.setNextNode(head.nextNode().nextNode());
        }

        public void RemoveLast()
        {
            tail.nodeBefore().nodeBefore().setNextNode(tail);
            tail.setNodeBefore(tail.nodeBefore().nodeBefore());
        }

        #endregion

        #region ICollection
        public void Add(T item)
        {
            this.AddFirst(item);
        }

        public void CopyTo(T[] array, int arrayIndex)
        {
            foreach (var data in this)
            {
                array[arrayIndex] = data;
                arrayIndex++;
            }
        }

        public int Count
        {
            get
            {
                int count = 0;
                foreach (var item in this)
                {
                    count++;
                }
                return count;
            }
        }

        public bool IsReadOnly
        {
            get { return false; }
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node<T> n = head.nextNode();

            while (n != tail)
            {
                yield return n.getInfo();
                n = n.nextNode();
            }
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public bool Remove(T information)
        {
            Node<T> search = this.Find(information);
            Node<T> n = head.nextNode();

            while (n != tail)
            {
                if (n == search)
                {
                    n.nodeBefore().setNextNode(n.nextNode());
                    n.nextNode().setNodeBefore(n.nodeBefore());
                    return true;
                }
            }

            return false;
        }

        #endregion

        #region Properties
        public bool Empty
        {
            get
            {
                return head == null;
            }
        }
        #endregion


    }
}
