# include<cstdio>
# include<ctime>

/*********************************************************************************
 * 计算阶乘之和: S = 1! + 2! + ... + n!
 * 1. 计算只含有加法,减法和乘法的整数表达式除以正整数n的余数,可以在每步计算后对n取余,结果不变
 * 2. 程序修改为每一步都取余数
 * 3. 可以分别输入n = 20 40 80 160 1600 12800 25600 51200 查看S的结果
 * 4. 当输入 n = 21 23 时 S末6位不为940313,从n = 25之后S末6位均为940313
 * *******************************************************************************/


int main(){
    int n, S = 0;
    const int MOD = 1000000;

    scanf("%d", &n);
    getchar();

    // if(n > 25) n = 25;

    for(int i = 1; i <= n; i++){
        int factorial = 1;
        for(int j = 1; j <= i; j++)
            factorial = factorial * j % MOD;
        S = (S + factorial) % MOD;
    }

    printf("%d\n", S);
    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC); 
    getchar();

    return 0;
}