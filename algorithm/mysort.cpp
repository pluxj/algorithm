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
    //自顶向下
    void CSort::MergeSort(int *arr, int n) {
        __mergeSort(arr,0,n-1);
    }

    void CSort::__merge(int *arr, int l,int mid, int r) {
        //进行归并
        int aux[r-l+1];
        for(int i = l; i <= r;++i)
        {
            aux[i] = arr[i];
        }
        int i = l;
        int j = mid+1;
        for(int k = l;k<=r;k++)
        {
            if(aux[i-l] > aux[j-l])
            {
                arr[k] = aux[j-l];
                j++;
            }
            else if(aux[i-l] < aux[j-l])
            {
                arr[k] = aux[i-l];
                i++;
            }
            else if(i > mid)
            {
                arr[k] = aux[j-l];
                j++;
            }
            else if (j > r)
            {
                arr[k] = aux[i-l];
                i++;
            }
        }
    }

    void CSort::__mergeSort(int *arr, int l, int r) {
        if(l >= r )
            return;
        int mid = (l+r)/2;
        __mergeSort(arr,l,mid);
        __mergeSort(arr,mid+1,r);
        if(arr[mid] > arr[mid+1])
            __merge(arr,l,mid,r);
    }

    //自底向上
    void CSort::mergeSortBU(int *arr, int n) {
        for(int sz = 1;sz <=n ;sz += sz)
            for(int i = 0;i+sz<n;i+=sz+sz)
                __merge(arr,i,i+sz,min(i+2*sz-1,n-1));
    }
} // namespace myalgoritm
