/*******************************
 * 用1,2,3,...,9组成3个三位数abc,def和ghi,每个数字恰好使用一次,
 * 要求abc: def: ghi = 1: 2: 3  
 * 按照"abc def ghi "的格式输出所有解,每行一个解
 * 
 * 注:
 * 是否有不借助数组的方法?
 * 按照书本的安排,还没有介绍数组的概念
 * 
 * 分析 
 * 要求1,2,3,...,9组成3个三位数abc,def和ghi,每个数字恰好使用一次
 * 因此abc最小为123, 最大为3开头的三位数
 * ****************************/

# include<cstdio>

int main(){
    int abc, def, ghi;
    int a, b, c, d, e, f, g, h, i;
    
    for(abc = 123; abc <= 329; abc++){
        bool visit[10] = {false};
        
        a = abc/100;
        b = abc/10%10;
        c = abc%10;
        visit[a] = visit[b] = visit[c] = true;

        def = abc*2;
        d = def/100;
        e = def/10%10;
        f = def%10;
        visit[d] = visit[e] = visit[f] = true;

        ghi = abc*3;
        g = ghi/100;
        h = ghi/10%10;
        i = ghi%10;
        visit[g] = visit[h] = visit[i] = true;

        bool flag = true;
        for(int i = 1; i < 10; i ++){
            if(visit[i] != true){
                flag = false;
                break;
            } 
        }

        //printf("abc:%d def%d: ghi%d\n", abc,def,ghi);

        if(flag){
            printf("%d : %d : %d = 1 : 2 : 3\n", abc,def,ghi);
        }
    }

    getchar();
    return 0;
}