#include "mysort.h"

namespace myalgoritm
{
    void CSort::Selection(vector<int> arr)  
    {
        int N = arr.size();
        for(int i = 0 ; i < N; ++i)
        {
            int min = i;
            for(int j = i+1;j < N ;++j)
            {
                if(arr[j] < arr[min])
                {
                    min = j;
                }
            }
            swap(arr[i],arr[min]);
        }
    }

    void CSort::Insertion(vector<int> arr)
    {
        for(int i = 1;i < arr.size();++i)
        {
            for(int j = i;j > 0;--j)
            {
                if(arr[j] < arr[j-1])
                {
                    swap(arr[j],arr[j-1]);
                }
            }
        }
    }
} // namespace myalgoritm
