/********
 * 1.关于哨兵结点的作用,还是没有理解
 * 2.关于函数缺省参数的理解,以及重载函数的理解
 */
#include <iostream>

#include "DLList.h"

using std::cout;
using std::endl;

int main() {
    DLList list;

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

    cout << "指定位置插入元素:insert" << endl;

    cout << "2位置插入3"<< endl;
    list.insert(2, 3);

    cout << "输出结果:" << endl;
    list.print();

    cout << "指定位置删除元素:erase" << endl;
    cout << "4位置删除"<< endl;
    list.erase(4);

    cout << "输出结果:" << endl;
    list.print();

    return 0;
}