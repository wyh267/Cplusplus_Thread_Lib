
#include "COperatingSystemFactory.h"

#include "CLinuxOperatingSystem.h"
#include "CThread.h"

#include "CCountingSem.h"
#include "CLinuxCountingSem.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


static void threadEntry(unsigned long *threadParm)
{
	 CThread 	*pThread = (CThread *) threadParm[0];
	 CCountingSem *pSemaphore      = (CCountingSem *) threadParm[1];
	 //printf("Thread3....%ld,OS:%ld\n",threadParm[0],(unsigned long) pThread);

	if(pThread==NULL)
		{
			printf("Thread Error...\n");

		}else
			{
				//printf("Begain to Run....%ld\n",(unsigned long)pThread);
				pThread->threadEntry(pSemaphore);
			}




	  pthread_exit(0);

}



CLinuxOperatingSystem::CLinuxOperatingSystem():
COperatingSystem()
{

	mThreadId = 0;
}


CLinuxOperatingSystem::~CLinuxOperatingSystem()
{


}




bool CLinuxOperatingSystem::createThread(CThread *mThread,unsigned long stack_size)
{
	int rc;
	unsigned long arguments[4];
	bool result;
	if (mThread == NULL)
	{
		printf("CLinuxOperatingSystem::CreateThread() : Thread pointer is NULL!  Can't begin the thread... ");
		return false;
	}
	
	p_thread = mThread;


	p_sem=COperatingSystemFactory::newCountingSem(0);

	pthread_attr_init(&mThreadAttr);  //线程属性初始化
	pthread_attr_setschedpolicy(&mThreadAttr, SCHED_FIFO);
	pthread_attr_setscope(&mThreadAttr, PTHREAD_SCOPE_SYSTEM);
	pthread_attr_setstacksize(&mThreadAttr, stack_size);
   	//pthread_attr_setinheritsched(&mThreadAttr, PTHREAD_EXPLICIT_SCHED);

	
	memset(arguments, 0, sizeof(arguments));
	arguments[0] = (unsigned long) p_thread;   //参数传递
	arguments[1] = (unsigned long) p_sem;
	//printf("Thread2....%ld,OS:%ld\n",arguments[0],(unsigned long) p_thread);
	rc = pthread_create(&mThreadId, &mThreadAttr, (void * (*) (void *))threadEntry, arguments);      //启动ThreadEntrypoint函数创建实在线程

	if (rc != 0){            
		printf("CLinuxOperatingSystem::CreateThread() : Failed to create and start the thread! ");
		p_thread = NULL;
		mThreadId = 0;
		return false;
	}
	
	pthread_detach(mThreadId);

	result = p_sem->Get();

	
	return true;

}








void  CLinuxOperatingSystem::sleepSec(unsigned long sec)
{

	sleep(sec);

}










