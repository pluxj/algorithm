#ifndef MUDUO_HTTP_SERVER_BASE_INTERFACE
#define MUDUO_HTTP_SERVER_BASE_INTERFACE

#include "stdlib.h"
#include <map>
#include <string>
#include <iostream>
#include "rapidjson/document.h"
#include "err_string.h"

class CBaseInterface
{
public:
	CBaseInterface();
	~CBaseInterface();

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
};



#endif