using System;

namespace _01_Hello_World
{
    class Program
    {
        static void Main(string[] args)
        {
            string songLyrics = "You say goodbye, and I say hello";
            Console.WriteLine(songLyrics.Contains("goodbye"));
            Console.WriteLine(songLyrics.Contains("greetings"));

            Console.WriteLine(songLyrics.StartsWith("You"));
            Console.WriteLine(songLyrics.EndsWith("Hello"));
        }
    }
}
