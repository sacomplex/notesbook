//
// Created by sacomplex on 2018/11/15.
//

#include <iostream>
#include "BinTree.h"

using std::cout;
using std::endl;

int main(){
    BinTree bTree;

    cout<< "创建二叉树 \n";
    // AB#CD###EF### 结点缺少儿子用#补全
    bTree.createBinTree();
    cout<<"\n";

    // 测试二叉树遍历
    BinTreeNode* root = bTree.getRoot();

    cout<< "递归先根遍历 \n";
    bTree.preOrder(root);
    cout<<"\n";

    cout<< "非递归先根遍历 \n";
    bTree.NorecPreOrder(root);
    cout<<"\n";

    cout<< "递归中根遍历 \n";
    bTree.inOrder(root);
    cout<<"\n";

    cout<< "非递归中根遍历 \n";
    bTree.NorecInOrder(root);
    cout<<"\n";

    cout<< "递归后根遍历 \n";
    bTree.pastOrder(root);
    cout<<"\n";

    cout<< "非递归后根遍历 \n";
    bTree.NorecPastOrder(root);
    cout<<"\n";

    cout<< "层次遍历 \n";
    bTree.levelOrder(root);
    cout<<"\n";

    // 有问题
    /*
    cout<< "二叉树复制 \n";
    BinTree bTree_2;
    bTree_2.copyTree(bTree.getRoot());

    cout<< "二叉树副本层次遍历的测试 \n";
    BinTreeNode* root_2 = bTree_2.getRoot();
    bTree.levelOrder(root_2);
    cout<<"\n";
     /*



    return 0;
}
