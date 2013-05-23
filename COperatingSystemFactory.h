
#ifndef _COprationSsytemFactory_h_
#define _COprationSsytemFactory_h_
/********************************************************************************************
*
*File name: COperatingSystemFactory.h
*Author: Wu Yinghao
*Version: 0.0.1
*Date: 2013.5.20
*E-Mail: wyh817@gmail.com
*Description: this file is the simple factory class for building COperratinSystem CMutex etc...
*
********************************************************************************************/
#include <stdio.h>

class COperatingSystem;
class CCountingSem;
class CMutex;
class CMsgQueue;

class COperatingSystemFactory
{
	public:
		
		static COperatingSystem *newOperatingSystem();


		static CCountingSem  *newCountingSem(unsigned int init);

		static CMutex		    *newMutex(const char *pName=NULL);


		static CMsgQueue     *newMsgQueue(const char *pName=NULL);


};













#endif


