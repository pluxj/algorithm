#include <iostream>
using namespace std;
#define  N 100
class A
{
public:
    A& operator +=(const A &a)
    {
        this->m_inum  += a.m_inum;
        this->m_isock += a.m_isock;
        return *this;
    }

public:
    int m_inum;
    int m_isock;
};
int strcmp_my(char *a,char *b)
{
    int i;
    for( i = 0;a[i] == b[i]; i++)
        if(a[i] == 0) return 0;
        return a[i] - b[i];


}
int main() {

    char arr[]= {"woshinidaye"};
    char arr1[] = {"aoshinidaye"};
   int abc = strcmp_my(arr,arr1);
    A a;
    a.m_inum = 5;
    a.m_isock = 6;
    A b;
    b.m_inum = 7;
    b.m_isock = 8;
    a += b;
    cout << a.m_inum << endl;
    cout << a.m_isock << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}