#include <iostream>
#include "AStack.h"

using std::cout;
using std::endl;

int main() {
    AStack stack;
    int x;

    cout << "开始测试 \n";

    cout << "入栈测试 \n";
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout <<"当前栈的大小是: " << stack.size() << "\n";

    cout << "遍历栈 \n";
    stack.print();

    cout << "取出栈顶元素 \n";
    stack.peek(x);
    cout << "栈顶元素: " << x << "\n";


    cout << "出栈测试 \n";
    stack.pop(x);
    cout << "出栈元素: " << x << "\n";
    stack.pop(x);
    cout << "出栈元素: " << x << "\n";

    cout << "遍历栈 \n";
    stack.print();

    cout << "栈溢出测试 \n";
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << "遍历栈 \n";
    stack.print();

    return 0;
}