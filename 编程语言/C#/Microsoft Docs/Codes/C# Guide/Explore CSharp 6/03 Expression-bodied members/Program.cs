using System;

namespace _03_Expression_bodied_members
{
    public class Person
    {
        public string FirstName { get; }
        public string LastName { get; }
        public string MiddleName { get; } = "";

        public Person(string first, string last)
        {
            FirstName = first;
            LastName = last;
        }

        public Person(string first, string middle, string last)
        {
            FirstName = first;
            MiddleName = middle;
            LastName = last;
        }

        public override string ToString() => FirstName + " " + LastName; // Expression-bodied members

        public string AllCaps()
        {
            return ToString().ToUpper();
        }
    }

    public class Program
    {
        public static void Main()
        {
            var p1 = new Person("Bill", "Wagner");
            Console.WriteLine("The name: " + p1);
            var p2 = new Person("FirstName", "MiddleName", "LastName");
            Console.WriteLine("The name: " + p2);
        }
    }
}
