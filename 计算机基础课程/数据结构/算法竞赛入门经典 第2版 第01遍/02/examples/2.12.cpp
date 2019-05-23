/**************
 * 数据输入2
 * 输入一些整数(小于1000),求出它们的最小值,最大值和平均值(保留三位小数)
 * 例如
 *   输入: 2 8 3 5 1 7 3 6
 *   输出: 1 8 4.375
 * 
 * 输入包含多组数据
 * 每组数据
 *   第一行是表示有n个数
 *   第二行是输入的n个数
 *   
 * n = 0 作为输入结束标记,程序忽略这组数据 
 *   相邻两组数据之间应输出一个空行
 * 
 * 输入
 * 8
 * 2 8 3 5 1 7 3 6
 * 4
 * -4 6 10 0
 * 
 * 输出
 * Case 1: 1 8 4.375
 * Case 2:-4 10 3.000
 *****************/ 

# include<cstdio>

# define INF 100000000

int main(){

    int x, n = 0, min = INF, max = -INF, kase = 0;

    // scanf("%d", &n) 用于接受n,即该组数据的总个数
    // n 用于判断是否为0,来结束程序
    while(scanf("%d", &n) == 1 && n){ 
        
        int s = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &x);

            s += x;

            if(x < min)
                min = x;
            if(x > max)
                max = x;
            
            // printf("x = %d min = %d max = %d\n", x, min, max);
        }
        
        if(kase) // kase 为当前数据的组的编号
            printf("\n"); // 打印空行,分隔数据组
        
        printf("Case: %d: %d %d %.3f\n", ++kase, min, max, (double)s/n);
        
        min = INF, max = -INF; // 重置
    }

    return 0;
}
