


#include "TestThread.h"
#include "TestThreadB.h"
#include "CMsgQueue.h"
#include "COperatingSystemFactory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


int main()
{

	CMsgQueue *q=COperatingSystemFactory::newMsgQueue("B to A message Queue");

	
	TestThread *a=new TestThread("A");
	TestThreadB *b=new TestThreadB("B");

	a->setMsgQueue(q);
	b->setMsgQueue(q);

	a->run();
	b->run();


	while(1)
		;


}



