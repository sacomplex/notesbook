#include<cstdio>

int main(){
    int a, b ,t;

    scanf("%d%d", &a, &b);
    getchar();
    
    t = a;
    a = b;
    b = t;

    printf("%d %d\n", a, b);
    getchar();

    return 0;
}