/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
      
           int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
        if(ret > INT_MAX/10 || (ret == INT_MAX / 10 && x/10 > 7))
                return 0;

  if(ret < INT_MIN / 10 || (ret == INT_MIN / 10 && x / 10 < -8))
                return 0;


 ret = ret * 10 + x%10;
            x = x / 10;

        }

      
  return ret*flag;

   }
};
// @lc code=end

