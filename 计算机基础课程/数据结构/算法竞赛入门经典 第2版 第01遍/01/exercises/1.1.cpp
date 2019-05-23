#include<cstdio>

int main( ){
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);
    getchar();

    printf("%.3f", (a + b + c)/3.0);
    // printf("%.3f", (a + b + c)/3);
    getchar();
    return 0;
}
