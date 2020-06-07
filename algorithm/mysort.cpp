#include "mysort.h"
#include "stdlib.h"
#include <algorithm>
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


      int * aux = new int[r-l+1];
      for( int i = 0;i < r-l+1;++i)
          aux[i] = arr[i+l];


      int i = 0;
      int auxmid = mid - l;
      int j = auxmid+1;

      for(int k = 0;k <r-l+1;++k)
      {
          if(i > auxmid)
          {
              arr[k+l] = aux[j];
              j++;
          }
          else if(j > r-l)
          {
              arr[k+l] = aux[i];
              i++;
          }
         else if(aux[i] > aux[j])
          {
              arr[k+l] = aux[j];
              j++;
          }
         else
          {
             arr[k+l] = aux[i];
             i++;
          }
      }
        for(int i = 0;i < r-l+1;i++)
        {
            std::cout<< "arr[" <<  i<<"]" << "= " << arr[i] << " ";
        }
        std::cout << "\n";
    }

    void CSort::__mergeSort(int *arr, int l, int r) {

        if(l >= r)
            return;
        int mid = l + (r-l)/2;

        __mergeSort(arr,l,mid);
        __mergeSort(arr,mid+1,r);
            __merge(arr,l,mid,r);
    }

    //自顶向下
    void CSort::MergeSortT(int *arr, int n) {
        int *aux = new int[n]{0};
        __mergeSortT(arr,0,n-1,aux);
    }

    void CSort::__mergeT(int *arr, int l, int mid, int r, int *aux)  {
        //进行归并


      int i = l,j=mid+1;
      for(int k = l;k<=r;++k)
      {
          aux[k] = arr[k];
      }
      for(int k = l;k<=r;k++)
      {
          if(i>mid) arr[k] = aux[j++];
          else if(j>r) arr[k] = aux[i++];
          else if(aux[i] > aux[j]) arr[k] = aux[j++];
          else arr[k] = aux[i++];
      }
    }

    void CSort::__mergeSortT(int *arr, int l, int r, int *aux) {

        if(r <= l)
            return;
        int mid = l + (r-l)/2;
        __mergeSortT(arr,l,mid,aux);
        __mergeSortT(arr,mid+1,r,aux);
        //__mergeT(arr,l,mid,r,aux);
        __merge(arr,l,mid,r);
    }

    //自底向上
    void CSort::mergeSortBU(int *arr, int n) {
        for(int sz = 1;sz <n ;sz += sz)
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


    void CSort::heapSort(int *arr, int n) {
        for(int k = n/2;k>=1;k--){
            __sink(arr,k,n);
        }

            while(n > 1) {
                __exch(arr,1,n--);
                __sink(arr,1,n);
            }
    }

    void CSort::__sink(int *arr,int  k,int  n) {
       while(2*k <= n)
       {
           int j = 2*k;
          if(j < n && __less(arr,j,j+1))
              j++;
          if(!__less(arr,k,j))
              break;
          __exch(arr,k,j);
          k = j;
       }
    }

    void CSort::__exch(int *arr, int i, int j) {
        swap(arr[i-1],arr[j-1]);
    }

    bool CSort::__less(int *arr, int i, int j) {
        if(arr[i-1] < arr[j-1])
            return true;
        return false;
    }
} // namespace myalgoritm
