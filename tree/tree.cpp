//
// Created by zzy on 2018/10/12.
//

#include "tree.h"

#include <iostream>
#include <vector>
using namespace std;

void tree::InitTree(Node *&T,int arr[],int size) {
    T= new Node;
    T->data=arr[1];


}

void tree::AddTreeNode(pNode treeNode) {
    if(m_proot == nullptr)
        return;
    pNode node_temp = treeNode;
    std::vector<pNode> vctnode;

    while(node_temp->left != nullptr)
    {
            vctnode.push_back(node_temp->right);
            vctnode.push_back(node_temp->left);


    }

}

pNode tree::TreeFindNode(pNode treeNode, int data) {
    pNode ptr;
    if(treeNode == nullptr)
    {
        return nullptr;
    }
    if(treeNode->data == data)
    {
        return treeNode;
    }
    else
    {
        if(ptr = TreeFindNode(treeNode->right,data))
        {
            return ptr;
        }
        else if(ptr = TreeFindNode(treeNode->left,data))
        {
            return ptr;
        }
        else
            return nullptr;
    }
}