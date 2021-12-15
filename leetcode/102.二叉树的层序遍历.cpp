/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
               queue<TreeNode*> tree_queue;
	    vector<vector<int>> vec_ret;
    if(root)
    {
        tree_queue.push(root);
    }
	int length = 0;
	while (!tree_queue.empty())
	{
        length = tree_queue.size();
		vector<int> tmp;
		for(int i = 0; i < length;i++)
		{
			TreeNode* node = tree_queue.front(); tree_queue.pop();
			tmp.push_back(node->val);
			
            if(node->left)
				tree_queue.push(node->left);
			if (node->right)
				tree_queue.push(node->right);
		}
		vec_ret.push_back(tmp);
	}
	return vec_ret;
    }
};
// @lc code=end

