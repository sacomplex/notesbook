/*************************************
 * 竖式问题
 * 找出所有形如abc*de（ 三位数乘以两位数） 的算式， 使得在完整的竖式中，所有数字都属于一个特定的数字集合。 
 *     输入数字集合（ 相邻数字之间没有空格） ， 输出所有竖式。 
 *     每个竖式前应有编号， 之后应有一个空行。 最后输出解的总数。
 * 为了便于观察， 竖式中的空格改用小数点显示， 但所写程序中应该输出空格， 而非小数点）
 * 
 * 样例输入
 * 2357
 * 
 * 样例输出
 * <1>
 * ..775
 * X..33
 * -----
 * .2325
 * 2325.
 * -----
 * 25575
 * The number of solutions = 1
 * 
 * 分析:
 * 输入的一组数字定义了一个集合,然后从中选出两组数abc和de,进行乘法竖式计算,运算过程和结果也是由此集合的数字组成
 * 
 * sprintf:输出到字符串
 * printf:输出到屏幕
 * fprintf:输出到文件
 * 
 * strchr在一个字符串中查找单个字符
 * 
 * strlen获取字符串的实际长度,即结束标记之前的字符个数
 * 
 * 滥用“++”、 “—”、 “+=”等可以修改变量值的运算符很容易带来隐蔽的错误。 用-Wall命令编译来将其提示为未定义运算
 * 
 * echo 2357 | 3.4.exe
 * 
 * 疑问
 *    原代码为什么abc从111开始
 * **********************************/

#include<cstdio>
#include<cstring>

int main(){
    int count = 0;
    char  s[20], buf[99];
    scanf("%s", s);

    // 此处疑问 原代码为什么abc从111开始
    for(int abc = 100; abc <= 999; abc++)
        for(int de = 10; de <= 99; de++){
            int x = abc*(de%10), y = abc*(de/10), z = abc*de;
            sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z); // 将abc,de,x,y,z输出到字符串(即字符数组)中
            int ok = 1;
            
            for(int i = 0; i < strlen(buf); i++) // 判断abc,de,x,y,z是否存在于s字符数组中
                if(strchr(s, buf[i]) == NULL)
                    ok = 0;
            
            if(ok){
                printf("<%d>\n", ++count);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
            }
        }
    printf("The number of solutions = %d\n", count);
}

