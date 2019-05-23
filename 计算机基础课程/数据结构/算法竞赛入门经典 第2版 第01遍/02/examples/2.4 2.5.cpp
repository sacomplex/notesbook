# include<cstdio>

/******************
 * 角谷猜想/冰雹猜想
 ******************/

int main(){
    int n, count = 0; // int 一般为32位整数 -2^32 ~ 2^32-1

    scanf("%d", &n);
    getchar();

    while(n > 1){
        if(n % 2 == 1){
            n = n * 3 + 1;
            printf("%d\n", n);
        }
        else{
            n /= 2;
            printf("%d\n", n);
        }    
        
        count ++;
    }

    printf("%d\n", count);

    // 使用long long
    long long n2;

    scanf("%d", &n2);
    getchar(); 

    count = 0;
    while(n2 > 1){
        if(n2 % 2 == 1){
            n2 = n2 * 3 + 1;
            //printf("%d\n", n2);
        }
        else{
            n2 /= 2;
            //printf("%d\n", n2);
        }    
        
        count ++;
    }   

    printf("%d\n", count);
    getchar();    

    return 0;
}