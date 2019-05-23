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

        // ���ڴ��ַ�����Ƕ��ı��ʽ��д�ַ���������ͨ��������Щ�ַ��������������ַ���ֵ
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

            // �������ַ����ڲ����ʹ�õ��������ʽ
            var phrase = "the quick brown fox jumps over the lazy dog";
            var wordLength = from word in phrase.Split(' ') select word.Length;
            var average = wordLength.Average();
            Console.WriteLine(average);
            Console.WriteLine();

            // �������ڲ��ַ������ʽ��ִ�иü���
            Console.WriteLine($"The average word length is: {wordLength.Average()}");
            Console.WriteLine();

            // �ڴ�������ָ����ʽ�ַ���
            Console.WriteLine($"The average word length is: {wordLength.Average():F2}");
        }
    }
}
