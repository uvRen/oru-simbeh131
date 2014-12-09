using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using DataStructures;

namespace DubbelLinkedListTest
{
    [TestClass]
    public class LinkedListTest
    {
        [TestMethod]
        public void TestDubbelAddFirst()
        {
            LinkedList<int> lista = new LinkedList<int>();

            lista.AddFirst(10);
            Assert.AreEqual(10, lista.getFirst());
            lista.AddFirst(20);
            Assert.AreEqual(20, lista.getFirst());
            lista.AddFirst(30);
            Assert.AreEqual(30, lista.getFirst());

            Assert.AreEqual(true, lista.Count > 0);
        }

        [TestMethod]
        public void TestDubbelAddLast()
        {
            LinkedList<int> lista = new LinkedList<int>();

            lista.AddLast(50);
            Assert.AreEqual(50, lista.getLast());
            lista.AddLast(40);
            Assert.AreEqual(40, lista.getLast());
            lista.AddLast(30);
            Assert.AreEqual(30, lista.getLast());
            lista.AddLast(20);
            Assert.AreEqual(20, lista.getLast());
            lista.AddLast(10);
            Assert.AreEqual(10, lista.getLast());

            Assert.AreEqual(true, lista.Count > 0);
        }

        [TestMethod]
        public void TestDubbelClear()
        {
            LinkedList<int> lista = new LinkedList<int>();

            lista.AddFirst(30);
            lista.AddFirst(30);
            lista.AddFirst(30);
            lista.AddFirst(30);

            lista.Clear();

            Assert.AreEqual(0, lista.Count);
        }

        [TestMethod]
        public void TestDubbelRemoveFirst()
        {
            LinkedList<int> lista = new LinkedList<int>();

            lista.AddFirst(40);
            lista.AddFirst(30);
            lista.AddFirst(20);
            lista.AddFirst(10);

            lista.RemoveFirst();
            Assert.AreEqual(20, lista.getFirst());
            lista.RemoveFirst();
            Assert.AreEqual(30, lista.getFirst());
        }

        [TestMethod]
        public void TestDubbelRemoveLast()
        {
            LinkedList<int> lista = new LinkedList<int>();

            lista.AddFirst(40);
            lista.AddFirst(30);
            lista.AddFirst(20);
            lista.AddFirst(10);

            lista.RemoveLast();
            Assert.AreEqual(30, lista.getLast());
            lista.RemoveLast();
            Assert.AreEqual(20, lista.getLast());
        }

        [TestMethod]
        public void TestDubbelRemove()
        {
            LinkedList<int> lista = new LinkedList<int>();

            lista.AddFirst(40);
            lista.AddFirst(30);
            lista.AddFirst(20);
            lista.AddFirst(10);

            lista.Remove(10);
            Assert.AreEqual(20, lista.getFirst());
            lista.Remove(40);
            Assert.AreEqual(30, lista.getLast());
        }

        [TestMethod]
        public void TestDubbelContains()
        {
            LinkedList<int> lista = new LinkedList<int>();

            lista.AddFirst(50);
            lista.AddFirst(40);
            lista.AddFirst(30);
            lista.AddFirst(20);
            lista.AddFirst(10);

            Assert.AreEqual(true, lista.Contains(30));
            Assert.AreEqual(false, lista.Contains(60));
        }
    }
}
