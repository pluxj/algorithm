#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int Fibonacci(int n) {
    int i = 0;
    int j = 1;
    int ret = 0;
    for (int m = 0; m < n - 1; m++) {
        ret = i + j;
        j = i;
        i = ret;
    }
    return ret;

}

void RepalceString(char string[], int length) {
    if (string == nullptr)
        return;
    int num = 0;
    char *s = string;
    char *p1 = string + length;
    for (int i = 0; i < length; i++) {
        if (*s == ' ')
            num++;
        s++;
    }
    length = length + 2 * num;
    char *p2 = string + length;
    for (int i = 0; i < num; i++) {
        while (*p1 != ' ') {
            *p2 = *p1;
            p2--;
            p1--;
        }
        *p2 = '0';
        p2--;
        *p2 = '2';
        p2--;
        *p2 = '%';
        p2--;
        p1--;
    }
}
//
//int tiaotaijie(int n)
//{
//
//    std::cout << ++count << std::endl;
//    if(n <= 0)
//        return -1;
//    if(n == 1)
//        return 1;
//    if(n == 2)
//        return 2;
//    return tiaotaijie(n-1)+tiaotaijie(n-2);
//}
int strlength(const char* str)
{
     const char  * eos = str;
    char arr[] = "liuxinshagou";
    eos = arr;
    while(*++eos);
    return (eos-arr);
}


vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    //首先做插入排序，在插入排序的同时匹配arr2
    for(int i = 0;i < arr1.size();++i)
    {

        int tmp = arr1[i];
        int j = i+1;
        for(;j < arr1.size();++j)
        {
            if(tmp > arr1[j] )
            {
                arr1[j-1] = arr1[j];
            } else{
                break;
            }
        }
        arr1[j] = tmp;
    }
}


int main() {
    int n = 100;
    vector<int> vecarr;
    for(int  i = 0; i < 100; ++i)
    {
        vecarr.push_back(random() / 10 + 30);
    }
    for(auto i : vecarr)
    {
        cout << i << endl;
    }

//    int n = 10;
//
// //   int temp = tiaotaijie(n);
// //   std::cout << temp << std::endl;
//    char string1[20] = "zeng zhi yong";
//    int clength = strlength(string1);
//    std::cout << clength  << std::endl;
//    int length = strlen(string1);
//    RepalceString(string1, length + 1);
//    std::cout << string1 << std::endl;
//    std::cout << length << std::endl;
//   int k = Fibonacci(55);
// //   std::cout << k << std::endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}