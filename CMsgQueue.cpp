


#include "CMsgQueue.h"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>



CMsgQueue::CMsgQueue(const char *pName)
{
	if(pName!=NULL)
		{
			msg_queue_name=(char *)malloc(sizeof(strlen(pName)));
			strcpy(msg_queue_name,pName);
		}
}



CMsgQueue::~CMsgQueue()
{

}

