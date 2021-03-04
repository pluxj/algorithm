/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }

        if(!p || !q){
            return false;
        }

        
        if(p->val != q->val){
            return false;
        }

        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        while(!s.empty()){
            TreeNode* p1 = s.top(); s.pop();
            TreeNode* q1 = s.top(); s.pop();
            if(!p1 && !q1){
                continue;
            }
            if(!p1 || !q1)
                return false;
            if(p1->val != q1->val)
                return false;
            
            s.push(p1->left);
            s.push(q1->left);

            s.push(p1->right);
            s.push(q1->right);
        }
        return true;
    }
};
// @lc code=end

