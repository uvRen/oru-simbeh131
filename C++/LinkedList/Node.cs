﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    public class Node<T>
    {
        private T information { get; set; }
        private Node<T> next { get; set; }
        private Node<T> before { get; set; }

        public Node()
        {
            information = default(T);
            next = null;
            before = null;
        }

        public Node(T information)
        {
            this.information = information;
            next = null;
            before = null;
        }

        public Node<T> nextNode() 
        {
            return this.next;
        }

        public void setNextNode(Node<T> next)
        {
            this.next = next;
        }

        public Node<T> nodeBefore()
        {
            return this.before;
        }

        public void setNodeBefore(Node<T> before)
        {
            this.before = before;
        }

        public T getInfo()
        {
            return this.information;
        }
    }
}
