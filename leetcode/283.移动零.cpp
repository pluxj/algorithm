/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int j = 0, k = 0,i=0;
	while (i < nums.size())
	{
		while (i < nums.size() && nums[i] != 0)
		{
			i++;
		}
		j = i;
		while (i < nums.size() && nums[i] == 0)
		{
			i++;
		}
		if (i >= nums.size())
		{
			break;
		}
		k = i;
		swap(nums[k], nums[j]);
		i = j;
	}
    }
};
// @lc code=end

