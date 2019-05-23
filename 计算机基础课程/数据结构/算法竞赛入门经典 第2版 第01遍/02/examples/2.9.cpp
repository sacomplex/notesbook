/**************
 * 数据输入1
 * 输入一些整数(小于1000),求出它们的最小值,最大值和平均值(保留三位小数)
 * 例如
 * 输入: 2 8 3 5 1 7 3 6
 * 输出: 1 8 4.375
 * 
 * 注意:
 *   Windows平台:Enter 然后 Ctrl + Z
 *   Linux平台:Ctrl + D 
 *****************/ 

# include<cstdio>

int main(int argc, char const *argv[]){
    int x, n = 0, min, max, s = 0;

    while(scanf("%d", &x) == 1){
        s += x;

        if(x < min)
            min = x;
        if(x > max)
            max = x;
        
        n++;
    }

    printf("%d %d %.3f\n", min, max, (double)s/n);
    getchar();

    return 0;
}
