//
// Created by sacomplex on 2018/10/9.
//
/*****************
 * 说明1:与顺序栈有关的知识
 ****************/

#ifndef ASTACK_H_001
#define ASTACK_H_001

#include <iostream>
using std::cout;
using std::endl;

using DataType = int;

class AStack {
private:
    DataType *elements;
    int theSize; // 栈内元素数量
    int capacity; // 栈的容量
public:
    static const int defaultCapacity = 10; // 栈的默认容量

public:
    explicit AStack(int capa = defaultCapacity);
    ~AStack();

public:
    bool empty();
    bool isFull();
    int size();
   //  void clear();
    void print();


    bool push(const DataType& x);
    bool pop(DataType &x);
    bool peek(DataType &x);
};

AStack::AStack(int capa = defaultCapacity):theSize{0},capacity{capa}, elements{new DataType[capacity]}
{}

AStack::~AStack() {
    delete [] elements;
}

bool AStack::empty() {
    return theSize == 0;
}

int AStack::size() {
    return theSize;
}

bool AStack::isFull() {
    return theSize == capacity;
}

void AStack::print() {
    for(int i = 0; i < theSize; i++){
        cout << elements[i] << " ";
    }
    cout <<"\n";
}

bool AStack::push(const DataType &x) {
    if(isFull()){
        cout << "The Stack is full! \n";
        return false;
    }

    elements[theSize] = x;
    theSize++;
    return true;
}

bool AStack::pop(DataType &x) {
    if(empty()){
        cout << "The Stack is empty! \n";
        return false;
    }

    x = elements[theSize-1]; // 注意:theSize比数组实际位置大1
    theSize--;
    return false;
}

bool AStack::peek(DataType &x) {
    if(empty()){
        cout << "The Stack is empty! \n";
        return false;
    }

    x = elements[theSize-1];
    return true;
}

#endif //ASTACK_H_001