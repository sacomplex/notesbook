using System;

namespace _01_Read_only_auto_properties_enable_read_only_types
{
    public class Person
    {
        public string FirstName { get; }
        public string LastName { get; }

        public Person(string first, string last)
        {
            FirstName = first;
            LastName = last;
        }

        public override string ToString()
        {
            return FirstName + " " + LastName;
        }

        public string AllCaps()
        {
            return ToString().ToUpper();
        }
    }

    public class Program
    {
        public static void Main()
        {
            var p = new Person("Bill", "Wagner");
            Console.WriteLine("The name, in all caps: " + p.AllCaps());
            Console.WriteLine("The name: " + p);
        }
    }
}
