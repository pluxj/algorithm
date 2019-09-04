#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
   int reverse(int x)
   {
       int tmp,y=0;
      while(x!=0)
      {
          tmp = y * 10 + x % 10;
          if(x>0 && (tmp/10 < y)) return 0;
          if(x<0 && (tmp/10 > y)) return 0;
          y = tmp;
          x /= 10;
      }
       return y;

   }
};
int main() {
    Solution s1;
    int j =  s1.reverse(-123);
    cout<<j<<endl;

}