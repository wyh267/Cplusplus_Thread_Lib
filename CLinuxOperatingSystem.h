

#ifndef _CLinuxOprationSystem_h_
#define _CLinuxOprationSystem_h_
/********************************************************************************************
*
*File name: CLinuxOperatingSystem.h
*Author: Wu Yinghao
*Version: 0.0.1
*Date: 2013.5.20
*E-Mail: wyh817@gmail.com
*Description: this file is linux OS class which inheritance from COperatingSystem
*
********************************************************************************************/

#include <pthread.h>
#include "COperatingSystem.h"

class CCountingSem;
class CLinuxOperatingSystem : public COperatingSystem
{
	public:

		CLinuxOperatingSystem();

		~CLinuxOperatingSystem();



		virtual  bool createThread(CThread *mThread,unsigned long stack_size=8*1024);

		virtual void  sleepSec(unsigned long sec);


	private:

		//sem_t                               mSuspendSem;


    		pthread_t                           mThreadId;

   
    		pthread_attr_t                      mThreadAttr;


		CCountingSem		*p_sem;

};





#endif


