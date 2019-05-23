#include<cstdio>

int main(){
    int number;

    scanf("%d", &number);
    getchar();

    if(number * 95 > 300)
        printf("%.2f", number * 95 * 0.85); 
    else 
        printf("%d", number * 95); 

    getchar();

    return 0;
}