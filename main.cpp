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
    int *arr= new int[n]{0};

    create_array_rand(arr,n,10,200);

    //归并排序
    for(int i = 0;i < n;++i)
    {
        int nrand = (rand() % 100 )+ 51;
        arr[i] = nrand;
        maxPQ->insert(nrand);
    }
    //TEST MAXPQ
    arrPrint(arr,n);
    //sort1->MergeSortT(arr,n);
    if(IsSort(arr,n)){
        std::cout << "MergeSortT is sort" << "\n";
    }
    else{
        std::cout << "MergeSortT not sort" << "\n";
    }

    create_array_rand(arr,n,10,200);
    //选择排序
    sort1->Selection(arr,n);
    if(IsSort(arr,n)){
        std::cout << "Selection is sort" << "\n";
    }
    else{
        std::cout << "Selection not sort" << "\n";
    }
    create_array_rand(arr,n,10,200);
    //插入排序
    sort1->Insertion(arr,n);
    if(IsSort(arr,n)){
        std::cout << "Insertion is sort" << "\n";
    }
    else{
        std::cout << "Insertion not sort" << "\n";
    }

    //归并排序
    create_array_rand(arr,n,30,300);
    sort1->MergeSort(arr,n);
    if(IsSort(arr,n)){
        std::cout << "MergeSort is sort" << "\n";
    }
    else{
        std::cout << "MergeSort not sort" << "\n";
    }
    //自底向上归并
    int *meger_arr = new int[10]{0};
    create_array_rand(meger_arr,10,1,11);
    sort1->mergeSortBU(meger_arr,10);
    if(IsSort(meger_arr,10)){
        std::cout << "mergeSortBU is sort" << "\n";
    }
    else{
        std::cout << "mergeSortBU not sort" << "\n";
    }

    //快速排�
    create_array_rand(arr,n,10,80);
    sort1->QuickSort(arr,n);
    if(IsSort(arr,n)){
        std::cout << "QuickSort is sort" << "\n";
    }
    else{
        std::cout << "QuickSort not sort" << "\n";
    }

<<<<<<< HEAD
    //堆排序
    n = 10;
||||||| e5da259
    //堆排序
=======
    //堆排�
>>>>>>> 1defe84786d017b6e8c643b89c8a59c84bd95092
    create_array_rand(arr,n,90,999);

    arr[0] = 10000;

    sort1->heapSort(arr,n);

    if(IsSort(arr,n)){
        std::cout << "heapSort is sort" << "\n";
    }
    else{
        std::cout << "heapSort not sort" << "\n";
    }

    delete[] arr;

   //arrPrint(arr,n);
   system("pause");


}

