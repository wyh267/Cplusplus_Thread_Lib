


#ifndef _CLinuxCountingSem_h_
#define _CLinuxCountingSem_h_

/********************************************************************************************
*
*File name: CLinuxCountingSem.h
*Author: Wu Yinghao
*Version: 0.0.1
*Date: 2013.5.20
*E-Mail: wyh817@gmail.com
*Description: this file is linux sem class which inheritance from CCountingSem
*
********************************************************************************************/

#include "CCountingSem.h"


#include <sys/time.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>


class CLinuxCountingSem:public CCountingSem
{
	public:
		CLinuxCountingSem(unsigned int init_sem_count);
		~CLinuxCountingSem();


		 virtual bool                Get(Mode mode = kForever, unsigned long timeoutMS = 0) ;

    		 virtual bool                Post(void) ;




	private:

		sem_t		sem;


};







#endif



