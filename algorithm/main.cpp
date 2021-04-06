//
// Created by zzy on 2019-10-13.
//

#include <iostream>
#include <vector>
#include <string>
#include "mysort.h"
//#include "SortTest.h"
#include "MaxPQ.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;
using namespace myalgoritm;
void arrPrint(int arr[],int n){
    for(int i = 0;i < n;i++)
    {
        std::cout<< "arr[" <<  i<<"]" << "= " << arr[i] << std::endl;
    }

}

bool IsSort(int arr[],int n){
    for(int i = 0; i < n-1 ;++i)
    {
        if(arr[i] > arr[i+1])
            return false;
    }
    return  true;
}

void sink(vector<int>& nums,int k, int N)
{
    while(2*k <=N){
        int j = 2*k;
        if(j < N && nums[j] < nums[j+1]){
            j++;
        }
        if(nums[k]> nums[j])
            break;
        swap(nums[k],nums[j]);
        k = j;
    }
}

void sort_heap(vector<int>& nums,int N )
{
    for(int i = N/2;i >= 1;i--)
    {
        sink(nums,i,N);
    }
    while(N > 1)
    {
        swap(nums[1],nums[N--]);
        sink(nums,1,N);

    }
}


//{3,2,3,1,2,4,5,5,6}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heap_vec.resize(k+1);
        n_ = 0;
        for(int i = 0;i < nums.size();i++)
        {
            insert(nums[i]);
        }
        return heap_vec[1];

    }
    void insert(int v)
    {
        if(n_ >= heap_vec.size()-1)
        {
            if(heap_vec[1] < v)
            {
                del_min();
                insert(v);
            }

        }
        else{
            heap_vec[++n_] = v;
            swim(n_);
        }
    }

    void del_min()
    {
        int v = heap_vec[1];
        swap(heap_vec[n_--],heap_vec[1]);
        heap_vec[n_+1] = 0;
        sink(1);
    }
    void swim(int k)
    {
        while(k > 1)
        {
            int j = k /2;
            if(heap_vec[k] < heap_vec[j])
            {
                swap(heap_vec[k],heap_vec[j]);
                k = j;
            }
            else
                break;
        }
    }
    void sink(int k)
    {
        while(2*k <= n_){
            int j = 2*k;
            if(j < n_ && heap_vec[j] > heap_vec[j+1]){
                j++;
            }
            if(heap_vec[k] < heap_vec[j])
                break;
            swap(heap_vec[k],heap_vec[j]);
            k = j;
        }
    }
    int findMagicIndex(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int ret = nums[nums.size()-1];
        while(lo < hi)
        {
            int mid = (hi-lo) / 2;
            if(nums[mid] > mid)
            {
                hi = mid;
            }
            else if(nums[mid] == mid)
            {
                ret = mid < ret ? mid:ret;
                lo = mid;
            }
            else
            {
                lo = mid;
            }
        }
        if(ret == nums[nums.size()-1])
        {
            return -1;
        }
        return ret;
    }
private:
    vector<int> heap_vec;
    int n_;
};

int main() {
//    vector<string> ops = new vector<string>();
//    vector<double> val = new vector<double>();
//    string cumilater = "3 + 2";
    //CSort *sort1 = new CSort();
    vector<int> nums = {0, 2, 3, 4, 5};
    //sort_heap(nums,nums.size()-1);
    Solution s = Solution();
    std::cout << s.findMagicIndex(nums)<< "\n";
    return 0;
    MaxPQ *maxPQ = new MaxPQ(100);
   // int n = 100;
    int n = 100;
    int *arr = new int[n];

    for(int i = 0;i < n;++i)
    {
        int nrand = (rand() % 100 )+ 51;
        arr[i] = nrand;
        maxPQ->insert(nrand);
    }
    //TEST MAXPQ
    arrPrint(arr,n);
    //sort1->MergeSortT(arr,n);
//    arrPrint(arr,100);
//
//
//    sort1->MergeSort(arr,100);
    if(IsSort(arr,n))
        std::cout<< " is sort" << std::endl;
    else
        std::cout<< " is not sort" << std::endl;

   //arrPrint(arr,n);
   system("pause");


}

