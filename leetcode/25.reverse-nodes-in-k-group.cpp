/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        ListNode* Pre = pHead;
        ListNode* pEnd = pHead;
        while (pEnd)
        {
            int i = 0;
            for (; i < k && pEnd->next; i++)
            {
                pEnd = pEnd->next;
            }
            if(i != k ) break;
            ListNode* start = Pre->next;
            ListNode* next = pEnd->next;
            Pre->next = reverseList(start,pEnd); 
            start->next = next;
            Pre = start;
            pEnd = Pre;
        }
        return pHead->next;
        
    }
      ListNode *reverseList(ListNode* head,ListNode* tail)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        ListNode* stop = tail->next;
        while (cur != nullptr && cur != stop)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end

