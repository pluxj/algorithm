#ifndef MUDUO_HTTP_ERRSTRING_
#define MUDUO_HTTP_ERRSTRING_

#include "singleton.h"
#include <map>
#include <string>

enum ERR_CODE
{
    SUCCESS = 0,
    ERR_EXCEPTION = 1000,
    ERR_PARAM = 10001,
}

class ERR_STRING 
{
public:
    inline static void addErrString(const int &errCode,const std::string& errString)
    {
        mErrString_.insert(pair<int,const std::string>(errCode,errString));
    }
    inline static std::string& GetErrString(const int &errCode)
    {
        return mErrString_.get(errCode);
    }

private:
    std::map<int,std::string> mErrString_;
}

#endif // !MUDUO_HTTP_ERRSTRING_