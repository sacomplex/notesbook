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
    BinTreeNode* root; // �����

public:
    BinTree(){
        root = new BinTreeNode('\n');
    }
     ~BinTree(){delBinTree(); root = nullptr;}

public:
     BinTreeNode* getRoot(){ return root;}

public:

    /**
     * ���ó���ʼ����������
     */
    void createBinTree(){
        cout << "��ʼ����:" << endl;
        root = create();
        cout << "��������" << endl;
    }
    // BinTreeNode* create(int level);
    BinTreeNode* create();
    /**
     * �ǵݹ鴴��������
     */

    /**
     * �ݹ�ɾ��
     * @param t
     */
    void delBinTree(){del(root);}
    void del(BinTreeNode* t);

    // ��ȱ���
    // �ݹ�
    void preOrder(BinTreeNode* t) const;
    void inOrder(BinTreeNode* t) const;
    void pastOrder(BinTreeNode* t) const;
    // �ǵݹ�
    void NorecPreOrder(BinTreeNode* t) const;
    void NorecInOrder(BinTreeNode* t) const;
    void NorecPastOrder(BinTreeNode* t) const;

    // ��α���
    void levelOrder(BinTreeNode* t) const;
};

/**
 * ģ��ǰ��������ж������ĵݹ鴴��
 */
BinTreeNode* BinTree::create() {
    BinTreeNode *t;

    T item;
    cin >> item;

    if(item ==  '#'){ // �ݹ����
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
 * 1. �ǵݹ��ȸ�����, ����ջ��ʵ�� �Ƚ����
 * 2. �ж�ջ�Ƿ�Ϊ�ջ�����Ϊ�գ�
 *     ����Ϊ�գ��ͷ���������ջ��ֱ������Ϊ�գ�
 *         ������Ϊ�գ��ͳ�ջ��Ȼ������Һ��ӣ���ջ�����������ϵ�ѭ����
 *******************************/
void BinTree::NorecPreOrder(BinTreeNode *t) const {
    stack<BinTreeNode*> s;
    BinTreeNode* p = t;

    if(t == nullptr){
        cout << "��Ϊ��";
        return;
    }

    /*�ؼ�����*/
    while(p || !s.empty()){
        if(p){
            s.push(p);
            cout << p->data <<" ";
            p = p->left;
        }else{
            p = s.top(); // ����Ϊ�� ȡ��ջ��Ԫ��,���丳��p
            s.pop();     // ���������
            p = p->right;  // ׼�������Ҷ���
        }
    }
}

/*******************************
 * 1. �ǵݹ��и�����,����ջ��ʵ�� �Ƚ����
 *        1.1 ��ǵݹ��ȸ���������һ��
 * 2. �ж�ջ�����Ƿ�Ϊ�գ�
 *       ����Ϊ��,��������������ջ����Ϊ�գ����ջ��������ݣ�Ȼ�������������
 *
 *******************************/
void BinTree::NorecInOrder(BinTreeNode *t) const {
    stack<BinTreeNode*> s;
    BinTreeNode* p = t;

    if(t == nullptr){
        cout << "��Ϊ��";
        return;
    }

    /*�ؼ�����*/
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->left;
        }else{
            p = s.top(); // ����Ϊ�� ȡ��ջ��Ԫ��,���丳��p
            s.pop();     // ���������
            cout << p->data <<" ";
            p = p->right;  // ׼�������Ҷ���
        }
    }
}

/*******************************
 * 1.1 �ǵݹ�������,����ջ��ʵ�� �Ƚ����
 * 1.2 Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ�
 *     ��˶�����һ���P���Ƚ�����ջ��
 *         ���P���������Ӻ��Һ��ӣ������ֱ�ӷ�����������P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣
 *         �������������������P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
 *******************************/
void BinTree::NorecPastOrder(BinTreeNode *t) const {
    stack<BinTreeNode*> s;
    BinTreeNode* cur = nullptr; // ��¼��ǰҪ���ʵĽ��
    BinTreeNode* pre = nullptr; // ��¼��ǰ���ʹ��Ľ��

    s.push(t); // ��ջ

    while(!s.empty()){
        cur = s.top(); // ȡ��ջ��Ԫ��

        // ���������Ӻ��Һ���:cur->left == nullptr && cur->right == nullptr
        // �������ӻ����Һ���,�����Ѿ���������: pre != nullptr && (pre  == cur->left || pre == cur->right)
        if((cur->left == nullptr && cur->right == nullptr)
                || (pre != nullptr && (pre  == cur->left || pre == cur->right))){
            cout << cur->data << " ";
            s.pop(); // ����ջ��Ԫ��
            pre = cur;
        } else{
            if(cur->right != nullptr)
                s.push(cur->right); // �Ҷ�����ջ
            if(cur->left != nullptr)
                s.push(cur->left); // �������ջ
        }
    }
}

/***************************
 * 1. ��α���,��������ʵ�� �Ƚ��ȳ�
 * 2.1 ���ڵ����
 * 2.2 �ظ�������ֱ������Ϊ��
 *    2.1 �����зǿ�,ȡ��ͷ��㲢����
 *    2.2 ������ָ�벻��,������������;������ָ�벻��,�����Ҷ������
 ***************************/
void BinTree::levelOrder(BinTreeNode *t) const{
    if(t == nullptr)
        return;

    BinTreeNode* p;
    queue<BinTreeNode*> q; // ����

    q.push(t); // ��tѹ���β

    while(!q.empty()){
        p = q.front(); // ���ʶ��������类ѹ��(��ͷ)λ�õ�Ԫ��
        cout << p->data << " ";
        q.pop(); // �������������类ѹ��(��ͷ)λ�õ�Ԫ��

        if((p->left) != nullptr)
            q.push(p->left);
        if((p->right) != nullptr)
            q.push(p->right);
    }
}
#endif //KMP_BINTREE_H
