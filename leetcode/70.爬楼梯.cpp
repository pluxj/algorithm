/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
       double sqrt5 = sqrt(5);
       double fibn = pow((1+sqrt5)/2,n+1)-pow((1-sqrt5)/2,n+1);
       return (int)round(fibn/sqrt5);

    }
};
// @lc code=end

