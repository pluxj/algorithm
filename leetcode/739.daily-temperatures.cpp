#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> temp;
        vector<int> out(T.size(),0);
        temp.push(0);
        for(int i = 1;i < T.size();i++)
        {
                    while(!temp.empty() && T[i] - T[temp.top()] > 0)
                    {
                        if(T[i] - T[temp.top()] > 0 )
                        {
                            out[temp.top()] = i - temp.top();
                            temp.pop();
                        }
                        else
                            break;
                    }
                temp.push(i);
        }
        return out;
    }
};