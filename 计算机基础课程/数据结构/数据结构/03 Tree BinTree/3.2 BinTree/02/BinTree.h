//
// Created by sacomplex on 2018/11/15.
//

#ifndef KMP_BINTREE_H
#define KMP_BINTREE_H

#include <iostream>
#include <string>
#include <queue>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::stack;

using T = char;

struct BinTreeNode{
    BinTreeNode* left;
    BinTreeNode* right;
    T data;

    explicit BinTreeNode(T d = '\0' , BinTreeNode* l = nullptr, BinTreeNode* r = nullptr):left{l},right{r},data{d}{}
};

class BinTree {
private:
    BinTreeNode* root; // 根结点

public:
    BinTree(){
        root = new BinTreeNode('\n');
    }
     ~BinTree(){delBinTree(); root = nullptr;}

public:
     BinTreeNode* getRoot(){ return root;}

public:

    /**
     * 调用程序开始创建二叉树
     */
    void createBinTree(){
        cout << "开始输入:" << endl;
        root = create();
        cout << "结束输入" << endl;
    }
    // BinTreeNode* create(int level);
    BinTreeNode* create();
    /**
     * 非递归创建二叉树
     */

    /**
     * 递归删除
     * @param t
     */
    void delBinTree(){del(root);}
    void del(BinTreeNode* t);

    // 深度遍历
    // 递归
    void preOrder(BinTreeNode* t) const;
    void inOrder(BinTreeNode* t) const;
    void pastOrder(BinTreeNode* t) const;
    // 非递归
    void NorecPreOrder(BinTreeNode* t) const;
    void NorecInOrder(BinTreeNode* t) const;
    void NorecPastOrder(BinTreeNode* t) const;

    // 层次遍历
    void levelOrder(BinTreeNode* t) const;
};

/**
 * 模拟前序遍历进行二叉树的递归创建
 */
BinTreeNode* BinTree::create() {
    BinTreeNode *t;

    T item;
    cin >> item;

    if(item ==  '#'){ // 递归出口
        return nullptr;
    }

    t = new BinTreeNode(item);

    // t->left = create(level + 1);
    // t->right = create(level + 1);
    t->left = create();
    t->right = create();

    return t;
}

void BinTree::del(BinTreeNode* t) {
    if(t != nullptr){
        del(t->left);
        del(t->right);
        delete t;
    }
}

void BinTree::preOrder(BinTreeNode* t) const{
    if(!t) return;

    cout << t->data << " ";
    preOrder(t->left);
    preOrder(t->right);
}

void BinTree::inOrder(BinTreeNode *t) const{
    if(!t) return;

    inOrder(t->left);
    cout << t->data << " ";
    inOrder(t->right);

}

void BinTree::pastOrder(BinTreeNode *t) const{
    if(!t) return;

    pastOrder(t->left);
    pastOrder(t->right);
    cout << t->data << " ";
}

/*******************************
 * 1. 非递归先根遍历, 借助栈来实现 先进后出
 * 2. 判断栈是否为空或子树为空，
 *     若不为空，就访问左孩子入栈，直至左孩子为空，
 *         若左孩子为空，就出栈，然后访问右孩子，入栈，就这样不断的循环。
 *******************************/
void BinTree::NorecPreOrder(BinTreeNode *t) const {
    stack<BinTreeNode*> s;
    BinTreeNode* p = t;

    if(t == nullptr){
        cout << "树为空";
        return;
    }

    /*关键部分*/
    while(p || !s.empty()){
        if(p){
            s.push(p);
            cout << p->data <<" ";
            p = p->left;
        }else{
            p = s.top(); // 左孩子为空 取出栈顶元素,将其赋给p
            s.pop();     // 弹出左儿子
            p = p->right;  // 准备访问右儿子
        }
    }
}

/*******************************
 * 1. 非递归中根遍历,借助栈来实现 先进后出
 *        1.1 与非递归先跟遍历大致一样
 * 2. 判断栈和树是否为空，
 *       若不为空,继续将左子树进栈，若为空，则出栈，输出数据，然后访问右子树。
 *
 *******************************/
void BinTree::NorecInOrder(BinTreeNode *t) const {
    stack<BinTreeNode*> s;
    BinTreeNode* p = t;

    if(t == nullptr){
        cout << "树为空";
        return;
    }

    /*关键部分*/
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->left;
        }else{
            p = s.top(); // 左孩子为空 取出栈顶元素,将其赋给p
            s.pop();     // 弹出左儿子
            cout << p->data <<" ";
            p = p->right;  // 准备访问右儿子
        }
    }
}

/*******************************
 * 1.1 非递归后根遍历,借助栈来实现 先进后出
 * 1.2 要保证根结点在左孩子和右孩子访问之后才能访问，
 *     因此对于任一结点P，先将其入栈。
 *         如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
 *         若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
 *******************************/
void BinTree::NorecPastOrder(BinTreeNode *t) const {
    stack<BinTreeNode*> s;
    BinTreeNode* cur = nullptr; // 记录当前要访问的结点
    BinTreeNode* pre = nullptr; // 记录先前访问过的结点

    s.push(t); // 入栈

    while(!s.empty()){
        cur = s.top(); // 取出栈顶元素

        // 不存在左孩子和右孩子:cur->left == nullptr && cur->right == nullptr
        // 存在左孩子或者右孩子,但是已经被访问了: pre != nullptr && (pre  == cur->left || pre == cur->right)
        if((cur->left == nullptr && cur->right == nullptr)
                || (pre != nullptr && (pre  == cur->left || pre == cur->right))){
            cout << cur->data << " ";
            s.pop(); // 弹出栈顶元素
            pre = cur;
        } else{
            if(cur->right != nullptr)
                s.push(cur->right); // 右儿子入栈
            if(cur->left != nullptr)
                s.push(cur->left); // 左儿子入栈
        }
    }
}

/***************************
 * 1. 层次遍历,借助队列实现 先进先出
 * 2.1 根节点入队
 * 2.2 重复本步骤直到队列为空
 *    2.1 若队列非空,取队头结点并访问
 *    2.2 若其左指针不空,将其左儿子入队;若其右指针不空,将其右儿子入队
 ***************************/
void BinTree::levelOrder(BinTreeNode *t) const{
    if(t == nullptr)
        return;

    BinTreeNode* p;
    queue<BinTreeNode*> q; // 队列

    q.push(t); // 将t压入队尾

    while(!q.empty()){
        p = q.front(); // 访问队列中最早被压入(队头)位置的元素
        cout << p->data << " ";
        q.pop(); // 弹出队列中最早被压入(队头)位置的元素

        if((p->left) != nullptr)
            q.push(p->left);
        if((p->right) != nullptr)
            q.push(p->right);
    }
}
#endif //KMP_BINTREE_H
