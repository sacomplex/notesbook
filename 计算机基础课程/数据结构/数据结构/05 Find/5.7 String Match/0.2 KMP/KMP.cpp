//
// Created by sacomplex on 2018/10/14.
//

/***********************
 * KMP�㷨
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

    int k = -1; // ǰ׺
    int j = 0; // ��׺

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

    // i = 0, j = -1 û�н����ж�?
    int slen = s.size();
    int tlen = t.size();

    // �˴�����������? i < s.size() && j < t.size()
    // ʹ�����������j=-1ʱ�᲻�����ж�,ֱ������
    // ��֪����C++���Ƶ�����,���Ǳ�����������
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
    cout << "KMPģʽƥ���㷨: \n";

    string s {"ABCDEFGHIJ"};
    string t {"J"};
    int pos = -1;

    if(KMP(s, t, pos)){
        cout << "ƥ��ɹ�: " << s << "��" << t <<" λ��λ��: " << pos + 1 << "\n";
    }else{
        cout << "ƥ��ʧ��: " << s << "��" << t << "\n";
    }

    system("PAUSE");
    return 0;
}
