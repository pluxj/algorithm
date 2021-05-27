/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
 bool compare(int a, int b)
	{
		stringstream s1;
	    s1 << a << b;
	    stringstream s2;
	    s2 << b << a;
	    if (s1.str() < s2.str())
	    {
		    return true;
	    }
	    return false;
	}


	
	void Quick_sort(int a[], int n)
	{
		quick_sort(a, 0, n - 1);
	}

	void quick_sort(int a[], int l, int r)
	{
		if (l >= r)
		{
			return;
		}
		int p = partition_sort(a, l, r);
		quick_sort(a, l, p - 1);
		quick_sort(a, p + 1, r);


	}

	int  partition_sort(int arr[], int left, int right)
	{

		int value = arr[left];
		int i = left;
		int j = right + 1;
		while (true)
		{
			//while (arr[++i] <= value)
			while (!compare(arr[++i], value))
				if (i == right)
					break;
			//while(arr[--j] >= value)
			while (compare(arr[--j], value))
				if (j == left)
					break;
			if (i >= j)
				break;
			swap(arr[i], arr[j]);
		}
		swap(arr[j], arr[left]);
		return j;
	}

	string largestNumber(vector<int>& nums) {
		Quick_sort(nums.data(), nums.size());
		stringstream ret;
        if(nums[0] == 0)
        {
            return "0";
        }
		for (int i = 0; i < nums.size(); i++)
		{
			ret << nums[i];
		}
		return ret.str();
    }
};
// @lc code=end

