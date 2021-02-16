/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
         std::string ret_str;
       ret_str.resize(indices.size());
       for(int i =0;i< indices.size();i++)
       {
           ret_str[indices[i]] = s[i];
       }
       return ret_str;
    }
};
// @lc code=end

