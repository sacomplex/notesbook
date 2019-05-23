/************************************
 * 3.1
 * 读入一些整数， 逆序输出到一行中
 * 
 * echo 10 9 8 7 6 5 4 | 3.1.exe
 * 
 * 关于C语言的memcpy函数
 * 如果声明的是“int a[maxn]， b[maxn]”， 是不能赋值b ＝ a的
 * 如果要从数组a复制k个元素到数组b, 可以这样做： memcpy(b， a， sizeof (int)*k)
 * 如果数组a和b都是浮点型的， 复制时要写成"memcpy(b， a， sizeof (double)*k)"
 * 如果需要把数组a全部复制到数组b中， 可以写得简单一些： memcpy(b， a， sizeof (a))
 * **********************************/

# include <cstdio>

# define maxn 105

int a[maxn];

int main(){
    int x, n = 0;

    while(scanf("%d", &x) == 1)
        a[n++] = x;

    for(int i = n- 1; i >= 0; i--)
        printf("%d ", a[i]);
    
    getchar();
    return 0;
}