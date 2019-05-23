/************************
 * 说明1:与链表有关的知识
 * 头结点(首结点/表头):第一个结点
 * 尾结点(表尾):最后一个结点
 * 哨兵结点:
 *        数据域为空,指针域指向实际的头结点
 *        作用:便于与头结点的插入,删除操作
 * 头指针:当哨兵结点存在时,指向哨兵结点,否则指向头结点
 * 尾指针:指向尾结点
 *
 * 说明2:
 * 为了专注于算法的实现,暂不实现一下内容
 * 1. 五大函数的全部构建
 * 2. 异常检测
 * 3. 容器的迭代器
 * 4. 加入模板
***************************/

/*单链表的实现*/
#ifndef SLLIST_H_001
#define SLLIST_H_001



#include <iostream>

using std::cout;
using std::endl;

using DataType = int;

class SLList {
private:
    // 定义结构体结点
    struct Node{
        DataType data;
        Node *next;

        Node(int d = 0, Node* n = nullptr)
                :data{d},next{n}
        {}
    };

private:
    int theSize; // 结点数量
    Node *head; // 头指针
    Node *tail; // 尾指针

public:
    /**
     * 构造函数
     */
    SLList();
    /**
     * 析构函数
     */
    ~SLList();

public:
    /**
    * 返回当前数组元素的数量
    * @return
    */
    int size();
    /**
     * 判断数组是否为空
     * @return
     */
    bool empty();
    /**
     * 链表置空
     */
    void clear();
    /**
     * 打印链表
     */
    void print();

    /**
    * 尾插
    * @param x
    */
    void pushBack(const DataType& x);
    /**
     * 尾删
     */
    void popBack();
    /**
     * 头插
     * @param x
     */
    void pushFront(const DataType& x);
    /**
     * 头删
     */
    void popFront();

    /**
     * 查找元素,返回结点位置
     * @param x
     * @return
     */
    int findPos(const DataType& x);
    /**
     * 查找元素,返回结点地址(有问题,Node为私有的)
     * @param x
     * @return
     */
    Node* findElem(const DataType& x);
    /**
     * 在位置pos,插入元素x
     * @param pos
     * @param x
     */
    void insertByPos(int pos, const DataType& x);
    /**
     * 在某一结点后插入元素x,(有问题,Node为私有的)
     * @param node
     * @param x
     */
    void insertByElem(Node* node, DataType& x);
    /**
     * 删除pos位置结点
     * @param pos
     */
    void eraseByPos(int pos);
    /**
     * 删除数据为x的结点
     * @param x
     * @return
     */
    void eraseByElem(const DataType& x);
};

SLList::SLList():theSize{0} {
    head = tail = new Node(); // 创建哨兵结点,并让头,尾指针指向哨兵结点
}

SLList::~SLList() {
    clear();
}

int SLList::size() {
    return theSize;
}

bool SLList::empty() {
    return size() == 0;
}

void SLList::clear() {
    Node* p = head->next; // 注意head指向哨兵结点,哨兵结点指向实际的头结点
    while(!empty()){
        head->next= p->next;
        delete p;
        p = head->next;
    }

    //最后,头结点和尾结点都指向哨兵结点
    tail = head;
    head->next = nullptr; // 哨兵结点指向空指针
}

void SLList::print() {
    Node* p = head->next;
    for(int i = 0; i < size(); i++){
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

void SLList::pushBack(const DataType &x) {
    tail->next = new Node(x);
    tail = tail->next;

    // 由于尾指针的指针域未置空,导致list无限延长
    // 有问题
    tail->next = nullptr;

    theSize++;
}

void SLList::popBack() {
    if(empty()){
        cout << "This SLList is empty !" << endl;
        return;
    }

    // 找到尾结点的前置结点
    Node* p = head->next;
    while(p->next != tail){
        p = p->next;
    }

    // 删除尾结点
    delete tail;
    tail = p;
    tail->next = nullptr;
    theSize--;
}

void SLList::pushFront(const DataType &x) {
    if(empty()){
        pushBack(x);
        return;
    }

    Node *p = new Node(x); // 创建结点
    p->next = head->next; // 将哨兵结点所指向的头结点连接到p
    head->next = p; //将哨兵结点指向p

    theSize++;
}

void SLList::popFront() {
    if(empty()){
        cout << "This SLList is empty !" << endl;
        return;
    }

    Node *p = head->next;
    head->next = p->next;

    if(size() == 1) // 若链表除了哨兵结点还有一个结点
    {
        tail = head;
        tail->next = nullptr;
    }

    delete p;
    theSize--;
}

int SLList::findPos(const DataType &x) {
    Node *p = head->next;
    for(int i = 0; i < size(); i++)
        if(p->data == x){
            return i;
        }else{
            p = p->next;
        }

     return -1;
}

SLList::Node* SLList::findElem(const DataType &x) {
    Node *p = head->next;
    for(int i = 0; i < size(); i++)
        if(p->data == x){
            return p;
        }else{
            p = p->next;
        }

    return nullptr;
}

void SLList::insertByPos(int pos, const DataType &x) {
    if(pos == 0){
        pushFront(x);
        return;
    }
    if(pos == theSize){
        pushBack(x);
        return;
    }

    Node *p = new Node(x);
    Node *q = head->next;
    for(int i = 1; i < theSize; i++){
        if(pos == i){
            p->next = q->next;
            q->next = p;

            theSize++;

            return;
        }
        q = q->next;
    }
}

/*思路没想好,Node为SLList私有的,那怎么调用?*/
void SLList::insertByElem(SLList::Node *node, DataType &x) {

}

void SLList::eraseByPos(int pos) {
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

    Node *p = nullptr;
    Node *q = head->next;;

    for(int i = 1; i < theSize; i++){
        if(pos == i){
            p = q->next;
            q->next = p->next;
            delete p;

            theSize--;

            return;
        }

        q = q->next;
    }
}

#endif //SLLIST_H_001
