#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include "list.h"
using namespace std;
int main() {
    list pList;
    srand(time(NULL));
    int a[10] = {0};
    for(int i = 0;i<10;++i)
    {
        a[i] = rand() / 10;
    }
    for(int j = 0;j<10;++j)
    {
        pList.insertHead(a[j]);
    }
    pList.TravelList();
    system("pause");
}