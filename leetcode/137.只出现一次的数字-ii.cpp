/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
int singleNumber(vector<int>& nums) {
    int single_num = 0;
    for (int i = 0;i< 32;i++)
    {
        int total = 0;
        
        for (int j = 0; j < nums.size(); j++)
        {
            total += ((nums[j] >> i) & 1);
        }
        if (total % 3)
        {
            single_num |= (1 << i);
        }
    }
    return single_num;
}
};
// @lc code=end

