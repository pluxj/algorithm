//
// Created by zzy on 2018/7/22.
//

#ifndef SHUANGZHAN_LIST_H
#define SHUANGZHAN_LIST_H


class Node
{
public:
    Node *pNext;
    Node *pCur;
    int data;
};
class list {
public:
    list();
    ~list();
    void insertHead(int data);
    bool deleteHead(int data);
    void insertTail(int data);
    void insert(Node cur,int data);
    Node* FindNode(int *lhead,int data);
    int listLen();
    bool TravelList();
private:
    Node *head;
    Node *tail;
    int m_iLen;
};


#endif //SHUANGZHAN_LIST_H
