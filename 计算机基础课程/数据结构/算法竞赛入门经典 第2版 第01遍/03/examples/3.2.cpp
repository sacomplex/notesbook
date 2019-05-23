/***********************
 * 开灯问题
 * 有n盏灯, 编号为1~n。 
 *   第1个人把所有灯打开,
 *   第2个人按下所有编号为2的倍数的开关(这些灯将被关掉),
 *   第3个人按下所有编号为3的倍数的开关(其中关掉的灯将被打开, 开着的灯将被关闭),
 *   依此类推。
 * 一共有k个人， 问最后有哪些灯开着？ 输入n和k， 输出开着的灯的编号。 k≤n≤1000。
 * 
 * echo 30 6 | 3.2.exe
 * 
 * 关于C语言的memset函数
 * memset(a, 0, sizeof(a)); 
 * 将数组元素置为0
 * ********************/

# include<cstdio>
# include<cstring>

# define maxn 1010

int a[maxn];

int main(){ 
    int n, k;

    memset(a, 0, sizeof(a));

    scanf("%d%d", &n, &k);

    // i 表示灯的序号
    // j 表示人
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= n; j++)
            if(j % i == 0) // 余数为0,即为整除,即为倍数
                a[j] = !a[j]; // 将原来的值取反

    for(int i = 1; i <= n; i++){
        if(a[i]){
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}