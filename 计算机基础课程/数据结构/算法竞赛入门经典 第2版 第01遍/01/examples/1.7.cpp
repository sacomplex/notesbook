# include<cstdio>
# include<cmath>

/****************
 * 将一个三位数反转
 ****************/
int main(){
    int n;
    //scanf("%d", &n);
    
    int m;
    m = (n%10)*100 + (n/10%10)*10 + (n/100);
    printf("%03d\n", m);
    getchar();
    
    return 0;
}