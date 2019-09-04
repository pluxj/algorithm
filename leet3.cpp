#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int y=x;
        int k=x;
        int tmp = 0;
        while(x != 0) {
            tmp = tmp * 10 + x % 10;
            x /= 10;
        }
        y=tmp;
        if(y == k)
            return true;
        else
            return false;
    }
};
int main() {
    Solution s1;
    bool j =  s1.isPalindrome(-121);
    cout<<j<<endl;

}