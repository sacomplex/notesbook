#include<cstdio>

int main(){
    int a ,b ,c;

    scanf("%d%d%d", &a, &b, &c);
    getchar();

    if( a + b > c && a + c > b && b + c > a)
        printf("yes");
    else
        printf("no");

    getchar();

    return 0;
}