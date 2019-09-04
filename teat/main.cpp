#include <iostream>
#include <boost/timer.hpp>
#include <vector>
#include <string>
#include "/Users/zengzhiyong/jsoncpp/jsoncpp/include/json/json.h"
using namespace std;
int arr[5] = {0,1};
int firstBadVersion(int arr[],int n)
{
    int mid = n /2;
    int cur = n;
    while(mid != 0)
    {
        if(arr[mid] == 0)
        {
            cur = mid;
            mid /= 2;
        }
        else
            break;
    }
    for(int i = mid;i<cur;i++)
    {
        if(arr[i] == 0)
            return i;
    }
    return 0;
}
int SpaceNum(char *str,int n)
{
    if(str == 0)
        return 0;
    char *p = str;
    char *q = str;
    int nums = 0;
    for(int i = 0;i < n;i++)
    {
//        if(str[i] != ' ')
//        {
//            swap(*p,*q);
//            p++;
//            q++;
//        }
//        else if(str[i] == ' ')
//        {
//            q++;
//            nums++;
//        }
        if(str[i] != ' ')
        {
            swap(*p,*q);
            p++;
            q++;
        }
        else if(str[i] == ' ')
        {
            q++;
            nums++;
        }
        else
        {
            *p = *q;
            *q++;
        }
    }
    return nums;
}
int Evaluate(const string &str)
{
    boost::timer tm;
    vector<int> nums;
    vector<char> charactor;
    int tmp=0;
    int t1=0,t2=0;
    char c=0;
    for(int i = 0;i<str.length();i++)
    {
        if(str[i]<='9' && str[i] >= '0') {
            nums.push_back(str[i] - '0');
            continue;
        }
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            charactor.push_back(str[i]);
            continue;
        }
        if(str[i] == ')')
        {
           c = charactor.back();
            charactor.pop_back();
            t1 = nums.back();
            nums.pop_back();
            t2= nums.back();
            nums.pop_back();
            if(c == '+')
            {
                nums.push_back( t1 + t2);
            }
            else if(c == '-')
            {
                nums.push_back( t1 - t2);
            }
            else if(c == '*')
            {
                nums.push_back( t1 * t2);
            }
            else if(c == '/')
            {
                nums.push_back(t1 / t2);
            }
        }
    }

    cout << tm.elapsed()<<endl;
    return nums.back();

}
int main() {
    std::string strValue = "{\"key1\":\"value1\",\"array\":[{\"key2\":\"value2\"},{\""
                           "key2\":\"value3\"},{\"key2\":\"value4\"}]}";
    Json::Reader reader;
    Json::Value value;
    using namespace Json;
    if(reader.parse(strValue,value))
    {
        string out = value["key1"].asString();
        cout << out << endl;
        const Value arrayObj = value["array"];
        for(int i = 0;i < arrayObj.size(); i++)
        {
            out = arrayObj[i]["key2"].asString();
            cout << out <<" ";
            if(i != arrayObj.size() -1)
                cout << "\n";
        }
    }
    return 0;
}
