//
// Created by sacomplex on 2018/11/30.
//

#ifndef DS_BSTREE_H
#define DS_BSTREE_H

using T = int;

typedef struct BSTNode{
    T key;
    BSTNode *lchild;
    BSTNode *rchild;

    BSTNode(BSTNode *l = nullptr, BSTNode *r = nullptr, T k):lchild{l}, rchild{r}, key{k}{}
};

class BSTree {
public:
    BSTNode* root;

public:
    BSTNode* BSTSearch(BSTNode * bt ,T key);
    void BSTInsert(BSTNode* &bt, T key);
    void CreateBST(T * key, int length);
    void Delete(T key);
};

BSTNode* BSTree::BSTSearch(BSTNode * bt ,T key){
    if(bt == nullptr)
        return nullptr;

    if(bt->key == key){
        return bt;
    } else if(bt->key > key){
        return BSTSearch(bt->lchild, key);
    } else{
        return BSTSearch(bt->rchild, key);
    }
}

void BSTree::BSTInsert(BSTNode* &bt, T key) {
    if(!bt){
        bt = new BSTNode(nullptr,nullptr,key);
    }

    if(bt->key == key){
        return;
    } else if(bt->key > key){
        return BSTInsert(bt->lchild, key);
    } else{
        return BSTInsert(bt->rchild, key);
    }
}

void BSTree::CreateBST(T *key, int length) {
    for(int i = 0; i < length; i++){
        BSTInsert(root, key[i]);
    }
}

#endif //DS_BSTREE_H
