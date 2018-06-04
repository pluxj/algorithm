#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> sum;

        for(int i = 0;i!= nums.size();i++)
        {
           for(int j =i+1;j!=nums.size();j++) {
               if (target - nums[i] == nums[j]) {
                   sum.push_back(nums[i]);
                   sum.push_back(nums[j]);
                   return sum;
               }
           }


        }
    }
};
int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    for(int i= 0;i<4;i++)
        cout<<nums[i]<<endl;
    Solution s1;
    s1.twoSum(nums,9);
    cout<<s1.twoSum(nums,9)[0]<<endl;
    cout<<s1.twoSum(nums,9)[1]<<endl;
    vector<int> ret(s1.twoSum(nums,9));

    cout<<ret[0]<<"+"<<ret[1]<<endl;


}