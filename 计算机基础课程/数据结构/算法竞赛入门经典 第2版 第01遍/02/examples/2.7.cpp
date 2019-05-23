# include<cstdio>
# include<ctime>

/*************************************
 * 计算阶乘之和: S = 1! + 2! + ... + n!,取其末6位
 * **********************************/

int main(){
    long long n, S = 0;

    scanf("%d", &n);
    getchar();

    for(int i = 1; i <= n; i++){
        int factorial = 1;
        for(int j = 1; j <= i; j++)
            factorial *= j;
        S+=factorial;
    }

    printf("%lld\n", S);
    printf("%d\n", S % (1000000));

    /**************************************************
     * (double)clock() / CLOCKS_PER_SEC 获得程序运行时间 
     * echo 20|xxx 
     *   使用管道命令 可以获得扣除键盘输入的程序真正运行时间
     *   xxx为可执行程序的名字 
     * *************************************************/
    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC); 
    getchar();

    return 0;
}