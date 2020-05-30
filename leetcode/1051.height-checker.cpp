/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> idx;
        for(int i = 0;i <= 100;++i)
        {
            idx.push_back(0);
        }
        for(int i = 0;i < heights.size();++i)
        {
            idx[heights[i]]++;
        }
        int move = 0;
        for(int i = 1,j=0;i<=100;++i)
        {
            while(idx[i]-- > 0)
            {
                if(heights[j++] != i)
                {
                    move++;
                }
            }
        }
        return move;
    }
};
// @lc code=end

