/**********************************
 * 设需要输出2， 4， 6， 8， …， 2n， 每个一行， 能不能通过对程序2-1进行小小的改动来实现呢？ 为了方便， 现把程序复制如下
 * 任务一 修改for循环体
 * 任务二 修改循环for语句
 * ********************************/
#include<cstdio>
int main() {
    int n;

    scanf("%d", &n);
    getchar();

    for(int i = 1; i <= n; i++)
        printf("%d\n", i*2);
    
    printf("***************\n");
    
    for(int i = 2; i <= 2*n; i = i + 2)
        printf("%d\n", i);

    getchar();
    return 0;
}