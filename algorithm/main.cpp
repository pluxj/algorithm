//
// Created by zzy on 2019-10-13.
//

#include <iostream>
#include <vector>
#include <string>
#include "mysort.h"
#include "SortTest.h"
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
int main() {
//    vector<string> ops = new vector<string>();
//    vector<double> val = new vector<double>();
//    string cumilater = "3 + 2";
    CSort *sort1 = new CSort();
    MaxPQ *maxPQ = new MaxPQ();
    int n = 100;
    int *arr = new int[100];

    for(int i = 0;i < 100;++i)
    {
        int nrand = (rand() % 100 )+ 51;
        arr[i] = nrand;
  //      maxPQ->insert(nrand);
    }
    //TEST MAXPQ
    sort1->heapSort(arr,100);
//    arrPrint(arr,100);
//
//
//    sort1->MergeSort(arr,100);
    if(IsSort(arr,100))
        std::cout<< " is sort" << std::endl;
    else
        std::cout<< " is not sort" << std::endl;

   arrPrint(arr,100);



}

