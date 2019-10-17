/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        if(x < 0 )
            flag = -1;
        int ret = 0;
        while(x / 10)
        {
            ret = ret * 10 + x%10;
            x = x / 10;
        }
         ret = ret * 10 + x%10;
          
        return ret*flag;
    }
};
// @lc code=end

