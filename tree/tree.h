//
// Created by zzy on 2018/10/12.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

typedef struct Node
{
    Node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    int data;
    Node *left;
    Node *right;
    Node *parent;
}*pNode,Node;
class tree {
private:
    void InitTree(Node *&T,int arr[],int size);   // 初始化树
    void AddTreeNode(pNode treeNode);  //添加节点
    pNode TreeFindNode(pNode treeNode,int data);
    pNode SearchNode(int nodeindex);  //查找结点
    pNode TreeLeftNode(pNode treeNode);
    pNode TreeRightNode(pNode treeNode);
    bool TreeIsempty();
    int TreeDepth(pNode treeNode);
    void ClearTree(pNode treeNode);
    void TreeNodeData(pNode treeNode);

private:
    pNode m_proot;
    int m_isize;
    int m_imaxsize;
};


#endif //TREE_TREE_H
