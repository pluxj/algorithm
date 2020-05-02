#include "router.h"


void CRouter::registerInterface(const std::string& strInterface, const CBaseInterface* &pinterface)
{
    mInterface_.insert(pair<std::string, CBaseInterface*>(strInterface,pinterface));
}

CBaseInterface* CRouter::getInterface(const std::string& strInterface)
{
    if(mInterface_.find(strInterface) != mInterface_.end())
    {
        return mInterface_.get(strInterface);
    }
    return nullptr;
}