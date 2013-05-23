
#include "CLinuxCountingSem.h"
#include <stdio.h>
#include <stdlib.h>



CLinuxCountingSem::CLinuxCountingSem(unsigned int init_sem_count):
CCountingSem()
{
	int result;
    	result = sem_init(&sem, 0, init_sem_count);
		
	    if (result != 0) {
	        printf("CLinuxCountingSem:  error\n");
	       
	    }


}


CLinuxCountingSem::~CLinuxCountingSem()
{


}


bool CLinuxCountingSem::Get(Mode mode , unsigned long )
{
    
	 if(sem_wait(&sem)==0)
	 	return true;
	 else
	 	return false;


}


bool CLinuxCountingSem::Post()
{
	sem_post(&sem);
    	return true;

}

