//
// Created by zzy on 2019-10-13.
//

#include <iostream>
#include <vector>
#include <string>
#include "mysort.h"
#include <algorithm>
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

void create_array_rand(int*arr,int n,int l,int r){
    for(int i = 0 ;i < n;++i) {
        int nrand = (rand() % r) + l;
        arr[i] = nrand;
    }
}
int main() {
//    vector<string> ops = new vector<string>();
//    vector<double> val = new vector<double>();
//    string cumilater = "3 + 2";
    CSort *sort1 = new CSort();
    MaxPQ *maxPQ = new MaxPQ();
    int n = 100;
    int *arr= new int[n]{0};

    create_array_rand(arr,n,10,200);

    //归并排序
    sort1->MergeSortT(arr,n);
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
    arrPrint(meger_arr,10);
    sort1->mergeSortBU(meger_arr,10);
    if(IsSort(meger_arr,10)){
        std::cout << "mergeSortBU is sort" << "\n";
    }
    else{
        std::cout << "mergeSortBU not sort" << "\n";
    }

    //快速排序
    create_array_rand(arr,n,10,80);
    sort1->QuickSort(arr,n);
    if(IsSort(arr,n)){
        std::cout << "QuickSort is sort" << "\n";
    }
    else{
        std::cout << "QuickSort not sort" << "\n";
    }

    //堆排序
    create_array_rand(arr,n,90,999);
    sort1->heapSort(arr,n);
    if(IsSort(arr,n)){
        std::cout << "heapSort is sort" << "\n";
    }
    else{
        std::cout << "heapSort not sort" << "\n";
    }

    MaxPQ maxpq(n);
    for(int i = 0;i < n;i++)
    {
        maxpq.insert(i);
    }
    
    

    delete[] arr;




}

