



#include "CThread.h"
#include "COperatingSystemFactory.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


CThread::CThread(const char *m_thread_name)
{
	p_thread_name=(char *)malloc(sizeof(strlen(m_thread_name)));
	strcpy(p_thread_name,m_thread_name);


	p_opration_system=COperatingSystemFactory::newOperatingSystem();

	

	if(p_opration_system==NULL)
		{
			printf(" OS Create Fail...\n");
			exit(0);
		}



}

CThread::~CThread()
{


}


void CThread::threadEntry(CCountingSem *pSemaphore)
{

	bool res;

	res=initializeThread();

	if(res)
	{
		pSemaphore->Post();
		
		mainLoop();
	
	}

	

}




bool CThread::initializeThread()
{

	return true;

}




bool CThread::run()
{
	if(!p_opration_system->createThread(this))
	{
		printf("Create Thread Fail....\n");
		exit(0);
	}


}


