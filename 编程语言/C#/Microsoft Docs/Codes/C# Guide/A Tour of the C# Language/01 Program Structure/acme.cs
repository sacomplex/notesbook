using System;

namespace Acme.Collections
{
    public class Stack
    {
        Entry top; // field 
        public void Push(object data) // method
        {
            top = new Entry(top, data);
        }

        public object Pop() // method
        {
            if (top == null)
            {
                throw new InvalidOperationException();
            }
            object result = top.data;
            top = top.next;
            return result;
        }

        class Entry // nested class
        {
            public Entry next; // field 
            public object data; // field 
            public Entry(Entry next, object data) // constructor
            {
                this.next = next;
                this.data = data;
            }
        }
    }
}