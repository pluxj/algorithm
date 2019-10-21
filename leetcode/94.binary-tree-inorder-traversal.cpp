/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vecret;
        stack<TreeNode*> s;
        if(root == nullptr)
            return vecret;
        TreeNode* p = root;
        s.push(root);
        while(p != nullptr || !s.empty())
        {
            while(p != nullptr)
            {
                if(p->left != nullptr)
                    s.push(p->left);
                p = p->left;
            }
            p = s.top();s.pop();
           
            vecret.push_back(p->val);
            if(p->right != nullptr)
                 s.push(p->right);
           
            p = p->right;
        }
        return vecret;
    }
};
// @lc code=end

