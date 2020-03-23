/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
   if (x < 0)
		return false;
	queue<int> q;
	int tmp = x;
    int data = 0;
	while (tmp > 0)
	{
		
		
        if(data  > INT_MAX/10 || (data==INT_MAX/10 && tmp%10 > 7))
			break;
		data = tmp % 10 + data * 10;
        tmp /= 10;
		
	}


	if (data != x)
		return false;

	return true;
    }
};
// @lc code=end

