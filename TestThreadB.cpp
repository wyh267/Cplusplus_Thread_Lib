

#include "TestThreadB.h"
#include "COperatingSystemFactory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


TestThreadB::TestThreadB(const char *m_name):
CThread(m_name)
{

	//add your code here
	
	
	

}



TestThreadB::~TestThreadB()
{

}

void TestThreadB::mainLoop()
{
	unsigned int code=0;
	char  *p_msg="hello Thread A";
	while(1)
		{
			printf(">>>>>>>%s is Running....send data to message queue...\n",p_thread_name);
			p_msg_send->sendMsg(code, (void *)p_msg);
			code++;
			p_opration_system->sleepSec(1);
		}


}



void TestThreadB::setMsgQueue(CMsgQueue *q)
{
	p_msg_send=q;
}



