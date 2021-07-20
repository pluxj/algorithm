/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    int _quick_partition(vector<vector<int>>& intervals,int left,int right)
{
	int value = intervals[left][0];
	int i = left;
	int j = right+1;

	while (true)
	{
		while (intervals[++i][0] <= value)
		{
			if (i == right)
			{
				break;
			}
		}
		while (intervals[--j][0] > value)
		{
			if(j == left)
				break;
		}
		if(i >= j)
			break;
		swap(intervals[i], intervals[j]);
	}
	swap(intervals[left], intervals[j]);
	return j;

}

void _quick_sort(vector<vector<int>>& intervals,int left,int right)
{
	if (left >= right)
		return;
	int p = _quick_partition(intervals, left, right);
	_quick_sort(intervals, left, p - 1);
	_quick_sort(intervals, p + 1, right);
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> out;
	_quick_sort(intervals, 0, intervals.size() - 1);

	out.push_back(intervals[0]);
	for (int i = 1; i < intervals.size(); i++)
	{
		vector<int> tmp = out.back();
		
		if (tmp[1] >= intervals[i][0])
		{	
			out.pop_back();
			if (tmp[1] < intervals[i][1])
			{
				tmp[1] = intervals[i][1];
			}
			out.push_back(tmp);
		}
		else
		{
			out.push_back(intervals[i]);
		}
	}
	return out;

}
};
// @lc code=end

