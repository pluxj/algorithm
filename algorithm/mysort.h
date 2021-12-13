

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
        void Selection(int* arr,int n);
        //插入排序
        void Insertion(int* arr,int n);

        //自顶向下的归并排序
        void MergeSort(int arr[],int n);
        void __mergeSort(int arr[],int l,int r);
        void __merge(int arr[],int l,int mid,int r);

        void MergeSortT(int arr[],int n);
        void __mergeSortT(int arr[],int l,int r,int aux[]);
        void __mergeT(int arr[],int l,int mid,int r,int aux[]);
        //自底向上
        void mergeSortBU(int arr[],int n);


        //快速排序
        void QuickSort(int arr[],int n);
        void __qiucksort(int arr[],int l,int r);
        int __partition(int arr[],int l,int r);

        //堆排序
        void heapSort(int arr[],int n);
        void __sink(int arr[],int k,int n);
        void __exch(int arr[],int i,int j);
        bool __less(int arr[],int i,int j);

        //非递归
        int binarySearch(int arr[],int n,int target);
        // 递归
        int binarySearchD(int arr[],int n,int target);
        int _binaryD(int arr[],int l,int r,int target);
    };
    
} // namespace algoritm

