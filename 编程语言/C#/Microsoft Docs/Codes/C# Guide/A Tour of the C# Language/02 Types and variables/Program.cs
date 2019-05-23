using System;

namespace _02_Types_and_variables
{
    class BoxingExample
    {
        static void Main()
        {
            int i = 123;
            object o = i;    // Boxing
            int j = (int)o;  // Unboxing
        }
    }
}
