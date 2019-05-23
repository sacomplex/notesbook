# include<cstdio>

int main(){
    double f, c;
    scanf("%f", &f);
    getchar();

    c = 5 * ( f - 32 ) / 9;

    printf("%.3f\n", c);
    getchar();

    return 0;
}