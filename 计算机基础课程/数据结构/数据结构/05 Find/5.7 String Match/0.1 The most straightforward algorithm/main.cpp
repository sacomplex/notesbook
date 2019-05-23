/********************************
 * 朴素的模式匹配算法
 *******************************/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

bool MSA_1(const string &s, const string &p, int &pos){
    int i = 0;
    /************
     * Ls - Lp >= p中未匹配的字符,才能继续比较si与p0,否则s剩下的长度小于p剩下的长度比较下去,没有意义
     * */
    while(i - j <= s.length() - p.length()){
        int j = 0;// j=0:s回溯后,重新比较
        // 如果没有j < p.length()这个条件,在比较p的最后一个字符可能会数组越界,继续比较
         while( s[i] == p[j] && j < p.length()){
            i++;
            j++;
        }

        if(j == p.length()){
            pos = static_cast<int>(i - p.length());
            return true;
        }

        i = i - j + 1; // 从比较成功的字符位置后继续比较
    }

    return false;
}

/* 问题:MSA_2的时间复杂度如何分析*/
bool MSA_2(const string &s, const string &p, int &pos) {
    int i = 0;
    int j = 0;

    while(i - j <= s.length() - p.length() && j < p.length()){
        if(s[i] == p[j]){
            i++;
            j++;
        }else{
            i = i - j + 1; // 从比较成功的字符位置后继续比较
            j = 0;
        }
    }

    if(j == p.length()){
        pos = static_cast<int>(i - p.length());
        return true;
    }

    return false;
}

int main() {
    cout << "朴素的模式匹配算法: \n";

    string s = "asdfgh";
    string p = "h";
    int pos = -1;

    if(MSA_1(s, p, pos)){
        cout << "匹配成功: " << s << "和" << p <<" 位置位于: " << pos;
    }else{
        cout << "匹配失败: " << s << "和" << p ;
    }
    
    return 0;
}