#include<cstdio>
#include<math.h>

/*******************
 * 找出四位数是"aabb"形式的完全平方数
 ******************/

int main(){
    // 对x开平方,判断其是否是整数
    for(int i = 1; i <= 9; i++)
        for(int j = 0; j <= 9; j++){
            int n = i * 1100 + j * 11;
            int m = floor(sqrt(n) + 0.5); // floor(x)取地板 , sqrt(n) + 0.5 减小误差

            if(m*m == n)
                printf("%d\n", n);
        }
    
    // 枚举平方根x,避开开平方操作
    for(int x = 1; ; x++){
        int n = x * x;
        if(n < 1000)
            continue;
        if(n > 9999)
            break;
        
        int hi = n / 100;
        int lo = n % 100;

        if(hi/10 == hi%10 && lo/10 == lo%10)
            printf("%d\n", n);
    }

    getchar();

    return 0;
}