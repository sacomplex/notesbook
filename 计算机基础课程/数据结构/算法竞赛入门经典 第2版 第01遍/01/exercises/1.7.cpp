#include<cstdio>

int main(){
    int year;

    scanf("%d", &year);
    getchar();

    if(year%4 == 0 && year%100 != 0 || year%400 == 0)
        printf("yes");
    else 
        printf("no");

    getchar();
    
    return 0;
}