


#include "CMutex.h"



#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>




CMutex::CMutex(const char *pName )
{
	if(pName!=NULL)
		{
			mutex_name=(char *)malloc(sizeof(strlen(pName)));
			strcpy(mutex_name,pName);
		}
}



CMutex::~CMutex()
{

}





