#ifndef MUDUO_HTTP_SERVER_BASE_INTERFACE
#define MUDUO_HTTP_SERVER_BASE_INTERFACE

#include <map>
#include <string>
#include <iostream>

class CBaseInterface
{
public:
	CBaseInterface();
	~CBaseInterface();

private:
	CBaseInterface(const CBaseInterface&);
	CBaseInterface& operator=(const CBaseInterface&);
};



#endif