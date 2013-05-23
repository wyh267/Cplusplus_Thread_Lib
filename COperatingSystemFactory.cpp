
#include "COperatingSystem.h"
#include "CLinuxOperatingSystem.h"

#include "CCountingSem.h"
#include "CLinuxCountingSem.h"


#include "CMutex.h"
#include "CLinuxMutex.h"


#include "CMsgQueue.h"
#include "CLinuxMsgQueue.h"

#include "COperatingSystemFactory.h"





COperatingSystem *COperatingSystemFactory::newOperatingSystem()
{

	return new CLinuxOperatingSystem();

}


CCountingSem  *COperatingSystemFactory::newCountingSem(unsigned int init)
{

	return new CLinuxCountingSem(init);

}


CMutex  *COperatingSystemFactory::newMutex(const char *pName)
{
	return new CLinuxMutex(pName);
}


CMsgQueue     *COperatingSystemFactory::newMsgQueue(const char *pName)
{
	return new CLinuxMsgQueue(pName);
}



