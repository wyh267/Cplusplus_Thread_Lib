

#ifndef _CLinuxMutex_h_
#define _CLinuxMutex_h_

/********************************************************************************************
*
*File name: CLinuxMutex.h
*Author: Wu Yinghao
*Version: 0.0.1
*Date: 2013.5.20
*E-Mail: wyh817@gmail.com
*Description: this file is linux mutex class which inheritance from CMutex
*
********************************************************************************************/




#include <stdio.h>
#include "CMutex.h"

#include <sys/time.h>
#include <pthread.h>
#include <errno.h>



class CLinuxMutex:public CMutex
{
	public:
		CLinuxMutex(const char *pName=NULL);
		~CLinuxMutex();

		virtual bool Lock();

		virtual bool UnLock();

	  private:
    
    		pthread_t                   	   m_thread;

    
    		pthread_mutex_t             m_mutex;

    
    		pthread_mutexattr_t         m_mtex_attr;

};






#endif


