#include "err_string.h"

static void initErrString()
{
    ERR_STRING::addErrString(ERR_CODE::SUCCESS,"ok");
    ERR_STRING::addErrString(ERR_CODE::ERR_EXCEPTION,"ERR_EXCEPTION");
    ERR_STRING::addErrString(ERR_CODE::ERR_PARAM,"ERR_PARAM");
}