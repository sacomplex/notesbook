#include<cstdio>

int main(){
    int a,b;

    scanf("%d%d", &a, &b);
    getchar();

    printf("%d %d\n", b, a);
    getchar();

    a = a + b;
    b = a - b;
    a = a - b;

    printf("%d %d\n", a, b);
    getchar();
    
    return 0;
}