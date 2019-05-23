using System;

namespace _06_Quick_and_easy_null_checks
{
    public class Program
    {
        public static void Main()
        {
            string s1 = null;
            // Console.WriteLine(s1.Length);
            // 借助 ?.（null 条1件）运算符，可轻松编写包含 null 值的逻辑，无需额外的 if 检查
            Console.WriteLine(s1?.Length);

            // 使用 `?[] `进行数组或索引访问
            char? c = s1?[0];
            Console.WriteLine(c.HasValue);

            // 多个条件运算符可以组合成一个表达式
            string s2 = null;
            bool? hasMore1 = s2?.ToCharArray()?.GetEnumerator()?.MoveNext();
            Console.WriteLine(hasMore1.HasValue);

            // 使用 null 合并运算符提供默认值
            bool hasMore2 = s2?.ToCharArray()?.GetEnumerator()?.MoveNext() ?? false;
            Console.WriteLine(hasMore2);

        }
    }
}
