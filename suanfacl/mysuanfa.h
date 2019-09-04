//
// Created by zzy on 2018/11/5.
//

#ifndef SUANFACL_MYSUANFA_H
#define SUANFACL_MYSUANFA_H

#include <iostream>
#include <algorithm>

using namespace std;
template <typename T>
class mysuanfa {
    //选择排序
    void SelectionSort(T arr[],int n)
    {
        if(arr == nullptr)
            return;
        for(int i = 0;i<n;i++)
        {
            int minIndex = i;  //声明一个最小索引，在下面的循环中找到那个最小索引.
            for(int j = i+1;j < n; j++)
            {
                if(arr[j] < arr[minIndex])
                    minIndex = j;
            }
            swap(arr[i],arr[minIndex]);
        }
    }

    //插入排序
    void InsertionSort(T arr[],int n)
    {
        if(arr == nullptr)
            return;
        for(int i = 0;i < n;i++)
        {
            T e = arr[i];  //将当前位置的 值取出来，在下面循环中依次比较找到当前元素最适合的位置，然后终止循环
            int j = i +1;
            for (; j < n; j++)
            {
                if(arr[j] < e)
                    arr[j-1] = arr[j];
                else
                    break;
            }
            arr[j] = e;
        }
    }
    //归并排序
    //自底向上的归并排序
    void mergeSortBU(T arr[],int n)
    {
        for(int sz = 1;sz <=n;sz+=sz)
            for(int i = 0;i+sz<n;i+=sz+sz)
                __merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
    }
    //自顶向下的归并排序
    void __merge(T arr[],int l,int mid,int r)
    {
        T aux[r-l+1];
        for(int i = l;i<= r ;i++)
            aux[i-l]=arr[i];
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
            else if(j >r)
           {
               arr[k] = aux[i-l];
               i++;
           }

        }
    }
    void __mergeSort(T arr[],int l,int r)
    {
        int mid = (l+r)/2;
        __mergeSort(arr,l,mid);
        __mergeSort(arr,mid+1,r);
        if(arr[mid] > arr[mid+1])
            __merge(arr,l,mid,r)

    }
    void MergeSort(T arr[],int n)
    {
       __mergeSort(arr,0,n-1);
    }

    //快速排序算法 此快速排序算法可以用随机快速算法进行改进，防止该数据是有序的数据，导致出现o(n^2)的情况发生
    int __partition(T arr[],int l,int r)
    {
        T v = arr[l];
        //j 指向当前< v 的最后一个元素  i:指向当前> v 的最后一个元素
        int j = l;
        for(int i = l+1;i<=r;++i)
        {
            if(arr[i] < v)
            {
                swap(arr[i],arr[j+1]);
                j++;
            }
        }
        swap(arr[l],arr[j]);
        return j;
    }
    void __quickSort(T arr[],int l,int r)
    {
        if( l >= r)
            return;
        int p = __partition(arr,l,r);
        __quickSort(arr,l,p-1);
        __quickSort(arr,p+1,r);
    }
    void QiuckSort(T arr[],int n)
    {
        __quickSort(arr,0,n-1);
    }
    //双路快速排序算法，此快速排序算法在单路快排的基础上将数据划分为<=v ,>=v的两个区间
    int __partition2(T arr[],int l,int r)
    {
        T v = arr[l];
        int i = l+1;
        int j = r;
        while(true)
        {
            //将元素分为 [l+1...i) <v .(j...r]>=v 的两个部分。但是没弄明白最后
            while(arr[i] < v && i<=r)
            {
                i++;
            }
            while(arr[j] > v && j>=l+1)
            {
                j--;
            }
            if(i > j)
                break;
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        swap(arr[l],arr[j]);
        return j;

    }
    void __quickSort2(T arr[],int l,int r)
    {
        if(l >= r)
        {
            return;
        }
        int p = __partition2(arr,l,r);
        __quickSort2(arr,l,p-1);
        __quickSort2(arr,p+1,r);
    }
    void QiuckSort2(T arr[],int n)
    {
        __quickSort2(arr,0,n-1);
    }
    //三路快速排序
    void __quickSort3(T arr,int l ,int r)
    {
        if(l >= r)
            return;
        int lt = l;
        int gt = r;
        T v = arr[l];
        int i = l+1;
        while(i < gt )
        {
            if(arr[i] < v)
            {
                lt++;
                i++;
            }
            else if(arr[i] > v)
            {
                gt--;
                swap(arr[i],arr[gt]);
            }
            else if(arr[i] == v)
                i++;
        }
        swap(arr[l],arr[lt]);
        __quickSort3(arr,l,lt-1);
        __quickSort3(arr,gt,r);

    }
    void QuickSort3(T arr[],int n)
    {
        __quickSort3(arr,0,n-1);
    }
    //堆排序

};


#endif //SUANFACL_MYSUANFA_H
