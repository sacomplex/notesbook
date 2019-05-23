using System;
using System.Linq;
using static System.Console; // Importing a single class

namespace _05_A_better_string_format
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

        // 用于从字符串和嵌入的表达式编写字符串，可以通过计算这些字符串来生成其他字符串值
        public override string ToString() => $"{FirstName} {LastName}";
        public string AllCaps() => ToString().ToUpper();
    }

    public class Program
    {
        public static void Main()
        {
            var p = new Person("Bill", "Wagner");
            Console.WriteLine($"The name, in all caps: {p.AllCaps()}");
            Console.WriteLine($"The name is: {p}");
            Console.WriteLine();

            // 可以与字符串内插配合使用的其他表达式
            var phrase = "the quick brown fox jumps over the lazy dog";
            var wordLength = from word in phrase.Split(' ') select word.Length;
            var average = wordLength.Average();
            Console.WriteLine(average);
            Console.WriteLine();

            // 可以在内插字符串表达式中执行该计算
            Console.WriteLine($"The average word length is: {wordLength.Average()}");
            Console.WriteLine();

            // 在大括号内指定格式字符串
            Console.WriteLine($"The average word length is: {wordLength.Average():F2}");
        }
    }
}
