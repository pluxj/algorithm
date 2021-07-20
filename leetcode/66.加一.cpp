/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int add_index = digits.size();
	for (int i = digits.size() - 1; i >= 0; --i)
	{
		if (digits[i] == 9)
		{
			add_index--;
			continue;
		}
		else
		{
			break;
		}
	}
	vector<int> ret = { 0 };
	if (add_index == 0)
	{
		ret.resize(digits.size() + 1);
		ret[0] = 1;
	}
	else
	{
		ret = digits;
		ret[add_index - 1] += 1;
		for (int i = add_index; i < ret.size(); ++i)
		{
			ret[i] = 0;
		}
	}
	return ret;
        
    }
};
// @lc code=end

