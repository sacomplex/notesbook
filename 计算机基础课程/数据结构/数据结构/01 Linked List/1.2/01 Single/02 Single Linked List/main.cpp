/*************
 * 问题:
 * 1. 由于尾指针的指针域未置空,导致list无限延长,需要注意,将tail->next置为nullptr
 * 2. 注意 for(int i = 0; i < theSize; i++),i的取值,注意是先i++然后进行判断,最后执行循环体,即i能取到最大值为theSize-1
 *************/
#include <iostream>

#include "SLList.h"


using std::cout;
using std::endl;

int main() {
    SLList list;

    cout << "单链表测试" << endl;

    cout << "尾插:pushBack" << endl;

    list.pushBack(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    cout << "输出结果:" << endl;
    list.print();

    cout << "尾删:popBack" << endl;
    list.popBack();
    list.popBack();

    cout << "输出结果:" << endl;
    list.print();

    cout << "头插:pushFront" << endl;
    list.pushFront(-1);
    list.pushFront(-2);
    list.pushFront(-3);

    cout << "输出结果:" << endl;
    list.print();

    cout << "头删:popFront" << endl;
    list.popFront();

    cout << "输出结果:" << endl;
    list.print();

    cout << "指定位置插入元素:insertByPos" << endl;
    /*
    cout << "0位置插入0"<< endl;
    list.insertByPos(0,0);

    cout << "输出结果:" << endl;
    list.print();
    system("PAUSE");
    */

    cout << "2位置插入3"<< endl;
    list.insertByPos(2, 3);

    cout << "输出结果:" << endl;
    list.print();

    cout << "指定位置删除元素:eraseByPos" << endl;
    cout << "4位置删除"<< endl;
    list.eraseByPos(4);

    cout << "输出结果:" << endl;
    list.print();

    return 0;
}