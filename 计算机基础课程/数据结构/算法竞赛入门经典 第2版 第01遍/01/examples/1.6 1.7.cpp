# include<cstdio>
# include<cmath>

/****************
 * 将一个三位数反转
 ****************/
int main(){
    int n;
    //scanf("%d", &n);
    n = 123;
    printf("%d%d%d\n", n%10, n/10%10, n/100);
    getchar();
    
    return 0;
}