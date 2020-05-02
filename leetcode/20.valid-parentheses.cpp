/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <stack>
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        if(s.length() == 1)
            return false;
          std::stack<char> t;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                t.push(s[i]);
            }
            else
            {
                if(t.empty())
                    return false;
                switch (s[i])
                {
                case ')':
                    if(t.top() != '(')
                        return false;
                    break;
                case '}':
                    if(t.top() != '{')
                        return false;
                    break;
                case ']':
                    if(t.top()!='[')
                        return false;
                    break;
                }
                t.pop();
            }
        }
        if(t.empty())
            return true;
        return false;
    }
};
// @lc code=end

