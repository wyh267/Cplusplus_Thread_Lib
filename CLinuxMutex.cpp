



#include "CLinuxMutex.h"





CLinuxMutex::CLinuxMutex(const char *pName):
CMutex(pName)
{

	m_thread = (pthread_t) 0;

    	pthread_mutexattr_init(&m_mtex_attr);
    	if (pthread_mutexattr_settype(&m_mtex_attr, PTHREAD_MUTEX_ERRORCHECK_NP))
        	printf("CLinuxMutex::CnlLinuxMutex() : Failed to set mutex attibutes\n");
               

   	 pthread_mutex_init(&m_mutex, &m_mtex_attr);



}


CLinuxMutex::~CLinuxMutex()
{

}

bool CLinuxMutex::Lock()
{

	bool locked     = false;
    	int result;
    
        
        result = pthread_mutex_lock(&m_mutex);
    

    switch (result) {
      case 0:
        m_thread = pthread_self();

        locked = true;
        break;
      case EDEADLK:
        locked = true;
        break;
      default:
        break;
    }

    return locked;

}

bool CLinuxMutex::UnLock()
{
	int result;
    	bool unlocked   = true;

	    if (m_thread!= pthread_self()) {
	        unlocked = false;
	        printf("CnlLinuxMutex::Unlock() :  Error - Mutex not locked or not owned by the thread! \n");

	    } else {
	         result = pthread_mutex_unlock(&m_mutex);
		  if(result<0)
		  	unlocked=false;
	    }
    	return unlocked;

}








