/****************************
 * 读写本地文件
 * 
 * 注意:
 *   改成标准输入输出,只需要
 *   fin = stdin;
 *   fout = stdout;
 *   不需要调用fopen和fclose
 * *************************/
# include<cstdio>

# define INF 100000000

int main(){
    FILE *fin, *fout;

    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");

    int x, n = 0, min = INF, max = -INF, s = 0;

    while(fscanf(fin, "%d", &x) == 1){
        s += x;

        if(x < min)
            min = x;
        if(x > max)
            max = x;
        
        // printf("x = %d min = %d max = %d\n", x, min, max);
        
        n++;
    }

    fprintf(fout, "%d %d %.3f\n", min, max, (double)s/n);

    fclose(fin);
    fclose(fout);

    return 0;
}