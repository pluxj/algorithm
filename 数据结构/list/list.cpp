//
// Created by zzy on 2018/7/22.
//

#include "list.h"
#include <iostream>
using namespace std;
list::list() {
    head = new Node;
    tail = new Node;
    head->pNext = tail;
    head->pCur = tail;
    head->data = 0;
    tail->pNext = head;
    tail->pCur = head;
    tail->data = 0;
    m_iLen = 0;
}
bool list::deleteHead() {

}

void list::insertTail(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->pNext = tail;
    temp->pCur = tail->pCur;
    tail->pCur->pNext = temp;
    tail->pCur = temp;
    ++m_iLen;
}

void list::insertHead(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->pCur = head;
    temp->pNext = head->pNext;

    head->pNext = temp;
    temp->pNext->pCur = temp;
    ++m_iLen;
}

Node* list::FindNode(int *lhead,int data) {
    lhead = head;
    Node *temp = lhead->pNext;
    if(temp->pNext == nullptr)
        return nullptr;
    if(temp->data != data)
        temp = FindNode(temp,data);
    return temp;
}

void list::insert(Node cur, int data) {
    Node *temp = new Node;
    temp->data = data;

    temp->pNext = cur.pNext;
    temp->pCur = cur;
    cur.pNext = temp;
    temp->pNext->pCur = temp;
    ++m_iLen;
}

bool list::deleteHead(int data) {
    if(head->pNext == head->pCur)
        return false;
    Node *temp = FindNode(head,data);
    if(temp == nullptr)
        return false;
    Node *cur = temp->pCur;
    Node *Next = temp->pNext;

    cur->pNext = Next;
    Next->pCur = cur;
    delete temp;
    temp = nullptr;
    --m_iLen;
    return true;
}

int list::listLen() {
    return m_iLen;
}

bool list::TravelList() {
    if(head->pNext == head->pCur) {
        cout << "此链表为空" << endl;
        return false;
    }
    Node * temp = head->pNext;
    while(temp->pNext != tail)
    {
        cout << temp->data << endl;
    }
    return true;

}

