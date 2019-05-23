//
// Created by sacomplex on 2018/10/14.
//

/***********************
 * KMP算法
 ************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using std::string;
using std::vector;
using std::cout;
using std::endl;

vector<int> getNext(string t){
    vector<int> next(t.size());
    next[0] = -1;

    int k = -1; // 前缀
    int j = 0; // 后缀

    while(j < t.size()){
        if(k == -1 || t[j] == t[k]){
            j++;
            k++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }

    return next;
}

bool KMP(string s, string t, int &pos){
    int i = 0;
    int j = 0;
    vector<int> next = getNext(t);

    // i = 0, j = -1 没有进入判断?
    int slen = s.size();
    int tlen = t.size();

    // 此处条件有问题? i < s.size() && j < t.size()
    // 使用这个条件当j=-1时会不进行判断,直接跳过
    // 不知道是C++机制的问题,还是编译器的问题
    while(i < slen && j < tlen){ //
        if( j == -1 || s[i] == t[j]){
            i++;
            j++;
        }else{
            j = next[j]; // j != -1 && s[i] != t[j]
        }
    }

    if(j == t.size()){
        cout << "i: " << i << "\n";
        pos = i - t.size(); // pos = i - j
        return true;
    } else{
        pos = -1;
        return false;
    }
}

int main() {
    cout << "KMP模式匹配算法: \n";

    string s {"ABCDEFGHIJ"};
    string t {"J"};
    int pos = -1;

    if(KMP(s, t, pos)){
        cout << "匹配成功: " << s << "和" << t <<" 位置位于: " << pos + 1 << "\n";
    }else{
        cout << "匹配失败: " << s << "和" << t << "\n";
    }

    system("PAUSE");
    return 0;
}
