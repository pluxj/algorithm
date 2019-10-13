

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace myalgoritm
{
    class CSort{
    public:
        CSort() {}
        ~CSort() {}
        //选择排序
        void Selection(vector<int> arr);
        //插入排序
        void Insertion(vector<int> arr);

        //自顶向下的归并排序
        void MergeSort(int arr[],int n);
        void __mergeSort(int arr[],int l,int r);
        void __merge(int arr[],int l,int mid,int r);

        //自底向上
        void mergeSortBU(int arr[],int n);

    };
    
} // namespace algoritm

