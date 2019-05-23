# include<cstdio>

int main(){
    int a, b, c, t;

    scanf("%d%d%d", &a, &b, &c);
    getchar();

    if(a > b){ // a <= b
        t = a;
        a = b;
        b = t;
    }

    if(a > c){ // a <= c, 
        t = a;
        a = c;
        c = t;
    }

    if(b > c){ // a = min{a, b, c}, b = min{b, c}
        t = b;
        b = c;
        c = t;
    }

    printf("%d %d %d", a, b, c);
    getchar();
    
    return 0;
}

