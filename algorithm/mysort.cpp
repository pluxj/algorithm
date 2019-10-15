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

      int j = mid+1;
      int aux[r-l+1];
      for( int i = l;i <= r;++i)
          aux[i-l] = arr[i];


      int i = l;
      for(int k = l;k <=r;++k)
      {
          if(i > mid)
          {
              arr[k] = aux[j-l];
              j++;
          }
          else if(j > r)
          {
              arr[k] = aux[i-l];
              i++;
          }
         else if(aux[i-l] > aux[j-l])
          {
              arr[k] = aux[j-l];
              j++;
          }
         else
          {
             arr[k] = aux[i-l];
             i++;
          }
      }

    }

    void CSort::__mergeSort(int *arr, int l, int r) {

        if(l >= r)
            return;
        int mid = l + (r-l)/2;
        __mergeSort(arr,l,mid);
        __mergeSort(arr,mid+1,r);
            __merge(arr,l,mid,r);
    }

    //自底向上
    void CSort::mergeSortBU(int *arr, int n) {
        for(int sz = 1;sz <=n ;sz += sz)
            for(int i = 0;i+sz<n;i+=sz+sz)
                __merge(arr,i,i+sz,min(i+2*sz-1,n-1));
    }



    //快速排序
    void CSort::QuickSort(int *arr, int n) {
        __qiucksort(arr,0,n-1);
    }

    void CSort::__qiucksort(int *arr, int l, int r) {
        if(l >= r)
            return;
        int p = __partition(arr,l,r);
        __qiucksort(arr,l,p-1);
        __qiucksort(arr,p+1,r);

    }

    int CSort::__partition(int *arr, int l, int r) {
        int v= arr[l];
        int i = l;
        int j = r+1;
        //为什呢最后要以j 与第一个元素进行交换，是因为在这里的定义中， i 为指向 大于 v 的索引，j 为指向小于 v 的索引。
        // 为了要将这个数组排序成 < v , = v ,> v 的三个区间，所以应该与l 所在的区间为小于v 的区间，故与j 进行交换
        while(true)
        {
            while(arr[++i] <= v)
                if(i == r)
                    break;

            while(arr[--j] >= v)
                if(j == l)
                    break;

            if(i >= j)
                break;
            swap(arr[i],arr[j]);

        }
        swap(arr[l],arr[j]);
        return j;
    }
} // namespace myalgoritm
