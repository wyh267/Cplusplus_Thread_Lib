


#include "TestThread.h"
#include "COperatingSystemFactory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


TestThread::TestThread(const char *m_name):
CThread(m_name)
{

	//add your code here
	


}



TestThread::~TestThread()
{

}

void TestThread::mainLoop()
{
	unsigned int code;
	void *p_msg;
	while(1)
		{

			p_msg_rev->recvMsg(code, p_msg);
			printf("<<<<<<<%s  is Running....recv data from message queue: code is : [%d]   data is : [%s] \n",p_thread_name,code,(char *)p_msg);

		}


}



void TestThread::setMsgQueue(CMsgQueue *q)
{
	p_msg_rev=q;
}



