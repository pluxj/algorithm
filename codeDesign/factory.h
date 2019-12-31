#include <string>
#include <iostream>
#include <pthread.h>
using namespace std;

class Pizza
{

};
class SimpleFactory
{
	Pizza* createPizza(string strType)
	{
		Pizza *pizza = nullptr;
		if (strType == "cheese") {
			
		}
	}
};