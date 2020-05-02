/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int narray[26] = {0};
        if(s.length() != t.length())
        {
            return false;
        }
        for(int i = 0;i < s.length();i++)
        {
            narray[s[i]-'a']++;
            narray[t[i]-'a']--;
        }
        for(int i = 0;i < 26;i++)
        {
            if(narray[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

