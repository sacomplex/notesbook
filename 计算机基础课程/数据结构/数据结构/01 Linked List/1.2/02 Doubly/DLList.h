/****************
 * 说明1:关于双项链表
 * 1. 双向链表的结点的指针域分为前后(或左右),分别指向结点前驱和后继结点
 * 2. 双向链表的尾结点的右指针域和头结点的左指针域为空
 *
 * 说明2:
 * 为了专注于算法的实现,暂不实现一下内容
 * 1. 五大函数的全部构建
 * 2. 异常检测
 * 3. 容器的迭代器
 * 4. 加入模板
******************/
#ifndef DLLIST_H_001
#define DLLIST_H_001

#include <iostream>

using std::cout;
using std::endl;

/*双项链表的实现*/
using DataType = int;

class DLList {
private:
    // 定义结构体结点
    struct Node{
        DataType data;
        Node *left;
        Node *right;

        Node(int d = 0, Node *l = nullptr, Node *r = nullptr)
                :data{d},left{l},right{r} {}
    };

private:
    int theSize; // 链表元素的数量
    Node* head; // 头指针,指向哨兵指针
    Node* tail; // 尾指针

public:
    DLList();
    ~DLList();

public:
    int size();
    bool empty();
    void clear();
    void print();

    void pushBack(const DataType& x);
    void popBack();
    void pushFront(const DataType& x);
    void popFront();
    int find(const DataType& x);
    void insert(int pos, const DataType& x);
    void erase(int pos);

};

DLList::DLList():theSize{0} {
    head = tail = new Node(); // 创建哨位节点
}

DLList::~DLList() {

}

int DLList::size() {
    return theSize;
}

bool DLList::empty() {
    return theSize == 0;
}

void DLList::clear() {
    Node *p = head->right;
    while(!empty()){
        head->right = p->right;
        p->right->left = head;
        delete p;
        theSize--;

        p = head->right;
    }

    tail = head;
    head->right= nullptr;
}

void DLList::print() {
    Node *p = head->right;
    for(int i = 0; i < theSize; i++){
        cout<< p->data << " ";
        p = p->right;
    }

    cout << "\n";
}

void DLList::pushBack(const DataType &x) {
    tail->right = new Node(x, tail);
    tail = tail->right;
    theSize++;
}

void DLList::popBack() {
    if(empty()){
        cout << "This DLList is empty !" << endl;
        return;
    }

    Node *p = tail;
    tail = tail->left;
    tail->right = nullptr;
    delete p;
    theSize--;
}

void DLList::pushFront(const DataType &x) {
    if(empty()){
        pushBack(x);
        return;
    }

    Node *p= new Node(x, head, head->right);
    head->right->left = p;
    head->right = p;

    theSize++;
}

void DLList::popFront() {
    if(empty()){
        cout << "This DLList is empty !" << endl;
        return;
    }

    Node *p = head->right;
    head->right = p->right;
    p->right->left = head;

    delete p;
    theSize--;
}

int DLList::find(const DataType &x) {
    Node *p = head->right;

    for(int i = 0; i < theSize; i++){
        if(p->data == x){
            return i;
        }else{
            p = p->right;
        }
    }

    return  -1;
}

void DLList::insert(int pos, const DataType &x) {
    if(pos == 0){
        pushFront(x);
        return;
    }
    if(pos == theSize){
        pushBack(x);
        return;
    }

    Node *q = head->right;
    for(int i = 0; i < theSize; i++){
        if(i == pos){
            Node *p = new Node(x, q->left, q);
            q->left->right = p;
            q->right = p;
            theSize++;
        }
        q = q->right;
    }
}

void DLList::erase(int pos) {
    if(empty()){
        cout << "This SLList is empty !" << endl;
        return;
    }

    if(pos == 0){
        popFront();
        return;
    }
    if(pos == theSize){
        popBack();
        return;
    }

    Node *q = head->right;
    for(int i = 0; i < theSize; i++){
        if(i == pos){
            Node *p = q->right;
            q->right = p->right;
            p->right->left = q;

            delete p;
            theSize--;
        }

        q = q->right;
    }
}
#endif // DLLIST_H_001
