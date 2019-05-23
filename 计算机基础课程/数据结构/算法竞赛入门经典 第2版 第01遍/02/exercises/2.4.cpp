/********************************
 * 输入两个正整数 n < m < 10^6 ,输出 1/(n)^2 + 1/(n + 1)^2 + ... + 1/m^2, 保留5位小数  
 * 输入包含多组数据, 结束标记为n = m = 0;
 * 样例输入
 * 2 4
 * 65536 655360
 * 0 0
 * 样例输出
 * Case 1:0.42361
 * Case 2:0.00001
 * 
 * 参考例2.12
 * 可能在n,m等于某个数之后结果不变
 * m当很大时对小数点后5位影响很小,就可以忽略了
 * 
 * printf("%lf", 1.0/(655360 * 655360)); 打印结果为inf
 * ******************************/

# include<cstdio>
# include<cmath>

int main(){
    while(scanf("%d%d", &n, &m) == 2 && n && m && n < m && m < pow(10.0, 6.0)){
        double s = 0;
        
        if( m >= 34403)
            m = 34403;

        for(int i = n; i <= m; i++){
            s = s + 1.0/(i*i);
        }

        if(kcase)
        printf("\n");

        printf("Case %d: %.5lf\n\n", kcase++, s);
        s = 0;
    }

    return 0;   
}