/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 */

// @lc code=start

 //* Definition for a binary tree node.
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

class Solution {
public:
//  void CreateTree(TreeNode* src,TreeNode* t1,TreeNode* t2){
//         if(t1 && t2)
//         {
//             return;
//         }
//         src = new TreeNode();
//         if(!t1 && !t2)
//         {
//             src->val = t1->val + t2->val;
//         }
//         else if(!t1)
//         {
//             src->val = t1->val;
//         }
//         else 
//         {
//             src->val = t2->val;
//         }
//     }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* src = nullptr;
       if(t1 == nullptr)
       {
           return t2;
       }
       if(t2 == nullptr)
       {
           return t1;
       }
     t1->val = t1->val + t2->val;
     t1->left= mergeTrees(t1->left,t2->left);
     t1->right = mergeTrees(t1->right,t2->right);
     return t1;
    }
   
};
// @lc code=end

