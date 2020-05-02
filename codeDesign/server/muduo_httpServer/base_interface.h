#ifndef MUDUO_HTTP_SERVER_BASE_INTERFACE
#define MUDUO_HTTP_SERVER_BASE_INTERFACE

<<<<<<< HEAD
#include "stdlib.h"
#include <map>
#include <string>
#include <iostream>
#include "rapidjson/document.h"
#include "err_string.h"
=======
#include <map>
#include <string>
#include <iostream>
>>>>>>> 74e7fb4eaf23446ac4f8697979a892adc2697ed9

class CBaseInterface
{
public:
	CBaseInterface();
	~CBaseInterface();

<<<<<<< HEAD
	void Handle(rapidjson::Value& jParam,rapidjson::Value& jBody);

	void response(rapidjson::Value &jBody);
private:
	CBaseInterface(const CBaseInterface&);
	CBaseInterface& operator=(const CBaseInterface&);

private:
	inline void SetResponseResult(const std::string& strRet,const std::string& strErrCode)
	{
		jBody_["_ret"] = strRet;
		jBody_["_errCode"] = strErrCode;
		jBody_["_errStr"] = ERR_STRING::GetErrString(atoi(strErrCode.c_str));
	}
private:
	rapidjson::Value jBody_;
=======
private:
	CBaseInterface(const CBaseInterface&);
	CBaseInterface& operator=(const CBaseInterface&);
>>>>>>> 74e7fb4eaf23446ac4f8697979a892adc2697ed9
};



#endif