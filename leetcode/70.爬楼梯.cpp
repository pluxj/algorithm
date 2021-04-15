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
    int climbStairs2(int n) {
       if(n == 1)
       {
           return 1;
       }
       if(n == 2)
       {
           return 2;
       }
       int f1 = 1;
       int f2 = 2;
       int fn = 0;
       while(n>2)
       {
           n--;
           fn = f1 + f2;
           f1 = f2;
           f2 = fn;
       }
       return fn;

    }
};
// @lc code=end

