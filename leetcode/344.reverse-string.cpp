/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.empty()){
            return;
        }
        auto head = s.begin();
        auto tail = s.end() -1;
        char tmp = '0';
        while(head < tail)
        {
            if(*head == *tail){
                  head++;
                  tail--;
                  continue;
            }
            tmp = *head;
            *head = *tail;
            *tail = tmp;
            head++;
            tail--;
        }
    }
};
// @lc code=end

