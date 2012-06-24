#include "includes.h"


XBMCRemoteConfig& XBMCRemoteConfig::instance()
{
        static XBMCRemoteConfig theInstance;
        return theInstance;
}
