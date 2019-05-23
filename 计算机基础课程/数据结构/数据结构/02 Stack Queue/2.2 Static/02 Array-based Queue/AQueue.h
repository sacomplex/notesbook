//
// Created by sacomplex on 2018/10/9.
//
/***************
 * 说明1:关于顺序队列
 * 1. 顺序的队列的实现方式:
 *  1)不要求队头元素必须存放在数组的第一个位置
 *  2)要求队头元素必须存放在数组的第一个位置
 * 2. 1)和2)都有缺点,使用环形队列解决
 * 3. 关于环形队列
 *      1)front队头位置和rear队尾位置的顺时针移动1位:(pos + 1) mod capacity
 *      2)front出,rear入
 **************/

#ifndef AQUEUE_H_001
#define AQUEUE_H_001

#include <iostream>

using std::cout;
using std::endl;

using DataType = int;

class AQueue {
private:
    int _front; // 队头位置
    int _rear; // 队尾位置
    int _size; // 元素数量
    int _capacity; // 队列容量

    DataType *_elements; // 存储元素

public:
    static const int defaultCapacity = 5;

public:
    explicit AQueue(int capa = defaultCapacity);
    ~AQueue();

public:
    bool empty();
    int size();
    int capacity();
    bool isFull();
    void traverse();

    bool push(const DataType& x);
    bool pop(DataType& x);

    bool front(DataType& x);
};

AQueue::AQueue(int capa)
    :_front{0},_rear{0},_size{0},_capacity{capa},_elements{new DataType[_capacity]}{}

AQueue::~AQueue() {
    delete []_elements;
}

bool AQueue::empty() {
    return _size == 0;
}

int AQueue::size() {
    return _size;
}

int AQueue::capacity() {
    return _capacity;
}

bool AQueue::isFull() {
    return _size == _capacity;
}

void AQueue::traverse() { // i的起始位置
    for(int i = _front; i < _size + _front; i++){
        cout << _elements[i % _capacity] << " ";
    }
    cout <<"\n";
}

/*注意,此处的取余用法*/
bool AQueue::push(const DataType &x) {
    if(isFull()){
        cout << "The Queue is full! \n";
        return false;
    }

    _elements[_rear] = x;
    _rear = (_rear + 1) % _capacity;
    _size++;
    return true;
}

bool AQueue::pop(DataType &x) {
    if (empty()){
        cout << "The Queue is empty! \n";
        return false;
    }

    x = _elements[_front];
    _front = (_front + 1) % _capacity;
    _size--;
    return true;
}

bool AQueue::front(DataType &x) {
    if (empty()){
        cout << "The Queue is empty! \n";
        return false;
    }

    x = x = _elements[_front];
    return true;
}
#endif //AQUEUE_H_001