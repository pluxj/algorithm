/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
/**
  Definition for a binary tree node.*/
  #include <stack>
  
  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *proot = nullptr;
        std::stack<TreeNode*> p;
        if(!root){
            return nullptr;
        }
        p.push(root);
        while(!p.empty()){
            TreeNode * tmp = nullptr;
            proot= p.top(); p.pop();
           
            if(!proot)
                continue;
            p.push(proot->left);
            p.push(proot->right);
            tmp = proot->left;
            proot->left = proot->right;
            proot->right = tmp;
           
           
        }
        return root;
    }
};
// @lc code=end

