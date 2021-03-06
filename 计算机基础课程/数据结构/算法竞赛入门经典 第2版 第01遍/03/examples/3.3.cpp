/********************************************
 * 蛇形填数
 * 在n×n方阵里填入1， 2， …， n×n(n≤8)， 要求填成蛇形
 * 例如， n＝ 4时方阵为：
 * 10 11 12 1
 *  9 16 13 2
 *  8 15 14 3
 *  7  6  5 4
 * 
 * 分析:
 * 需要二维数组
 * 第一步: 第1个格子的坐标是(0, n - 1)
 * 第二步: 向下(1, n - 1) (2, n - 1)... (n - 1 , n - 1)
 * 第三步: 向左(n - 1 , n - 1) (n - 1 , n - 2)...(n - 1, 1)
 * 第四步: 向上(n - 1, 1) (n - 2, 1)...(1, 1)
 * 第五步: 向右(1, 1) (1, 2) ... (1, n - 2)
 * 
 * 总结
 * 判断是否到达边界
 * 不应该重复以前的格子
 *   可以先将二维数组初始化为0,这样非零代表该格子已经被走过了
 * 
 * 注意
 * ++tot与tot++的区别
 * *****************************************/
# include<cstdio>
# include<cstring>

# define maxn 10

int a[maxn][maxn];

int main(){
    int n, x, y, tot = 0;

    scanf("%d", &n);

    memset(a, 0, sizeof(a));

    tot = a[x = 0][y = n - 1] = 1; // 第1个格子的坐标是(0, n - 1) 初始化为1

    while(tot < n*n){
        while(x+1 < n && !a[x+1][y]) // 判断是否到达边界,并且判断向下的一格是否已经走过了,a[++x][y], 纵坐标x + 1向下移动,并且赋值tot + 1
            a[++x][y] = ++tot;

        while(y-1 >= 0 && !a[x][y-1])
            a[x][--y] = ++tot;
        
        while(x-1 >= 0 && !a[x-1][y])
            a[--x][y] = ++tot;

        while(y + 1 < n && !a[x][y+1]){
            a[x][++y] = ++tot;
        }
    }

    for(x = 0; x < n; x++){
        for(y = 0; y < n; y++)
            printf("%3d", a[x][y]);
        printf("\n");
    }
        
    return 0;
}
