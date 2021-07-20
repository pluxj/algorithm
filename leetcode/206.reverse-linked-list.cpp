/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.*/

 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode*next = nullptr;
        ListNode*tmp = nullptr;
        tmp = head;
        while(tmp != nullptr){
            next = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = next;
        }
        return prev;
    }
};
// @lc code=end

