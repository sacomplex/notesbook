#include <iostream>

#include "AQueue.h"

using std::cout;
using std::endl;

int main() {
    AQueue queue;
    int x;

    cout << "顺序环形队列测试 \n";

    cout << "插入队列 \n";
    queue.push(0);
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "队列遍历 \n";
    queue.traverse();

    cout << "队列溢出测试 \n";
    queue.push(4);
    queue.push(5);

    cout << "队列遍历 \n";
    queue.traverse();

    cout << "队列删除测试 \n";
    queue.pop(x);
    cout << "删除元素: " << x << "\n";
    queue.pop(x);
    cout << "删除元素: " << x << "\n";
    queue.pop(x);
    cout << "删除元素: " << x << "\n";
    queue.pop(x);
    cout << "删除元素: " << x << "\n";
    cout << "队列遍历 \n";
    queue.traverse();

    return 0;
}