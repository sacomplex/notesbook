//
// Created by sacomplex on 2018/11/15.
//

#include <iostream>
#include "BinTree.h"

using std::cout;
using std::endl;

int main(){
    BinTree bTree;

    cout<< "���������� \n";
    // AB#CD###EF### ���ȱ�ٶ�����#��ȫ
    bTree.createBinTree();
    cout<<"\n";

    // ���Զ���������
    BinTreeNode* root = bTree.getRoot();

    cout<< "�ݹ��ȸ����� \n";
    bTree.preOrder(root);
    cout<<"\n";

    cout<< "�ǵݹ��ȸ����� \n";
    bTree.NorecPreOrder(root);
    cout<<"\n";

    cout<< "�ݹ��и����� \n";
    bTree.inOrder(root);
    cout<<"\n";

    cout<< "�ǵݹ��и����� \n";
    bTree.NorecInOrder(root);
    cout<<"\n";

    cout<< "�ݹ������� \n";
    bTree.pastOrder(root);
    cout<<"\n";

    cout<< "�ǵݹ������� \n";
    bTree.NorecPastOrder(root);
    cout<<"\n";

    cout<< "��α��� \n";
    bTree.levelOrder(root);
    cout<<"\n";

    // ������
    /*
    cout<< "���������� \n";
    BinTree bTree_2;
    bTree_2.copyTree(bTree.getRoot());

    cout<< "������������α����Ĳ��� \n";
    BinTreeNode* root_2 = bTree_2.getRoot();
    bTree.levelOrder(root_2);
    cout<<"\n";
     /*



    return 0;
}
