<<<<<<< HEAD
=======
#pragma once
>>>>>>> 74e7fb4eaf23446ac4f8697979a892adc2697ed9
#ifndef MUDUO_HTTP_SERVER_ROUTER
#define MUDUO_HTTP_SERVER_ROUTER

#include <map>
#include <string>
#include <iostream>
#include "base_interface.h"

class CRouter
{
public:
<<<<<<< HEAD
	CRouter() {};
	~CRouter() {};
=======
	CRouter();
	~CRouter();
>>>>>>> 74e7fb4eaf23446ac4f8697979a892adc2697ed9
	void registerInterface(const std::string& strInterface, const CBaseInterface* &pinterface);
	CBaseInterface* getInterface(const std::string& strInterface);
private:
	CRouter& operator=(const CRouter&);
	CRouter(const CRouter&);

private:
	std::map<std::string, CBaseInterface*> mInterface_;

};


#endif