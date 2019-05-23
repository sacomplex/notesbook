/******************************
 * 使用重定向读写文件
 * 不需要使用重定向,而使用标准输入输出删除"# define LOCAL"即可
 * 
 * 注意
 * VScode 重定向输出的路径和结果有问题
 * 直接运行生成的可执行文件则没有问题,应该VScode 设置的问题
 * **************************/

# define LOCAL

# include<cstdio>

# define INF 100000000

int main(){

# ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
# endif

    int x, n = 0, min = INF, max = -INF, s = 0;

    while(scanf("%d", &x) == 1){
        s += x;

        if(x < min)
            min = x;
        if(x > max)
            max = x;
        
        // printf("x = %d min = %d max = %d\n", x, min, max);
        
        n++;
    }

    printf("%d %d %.3f\n", min, max, (double)s/n);

# ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
# endif

    return 0;
}