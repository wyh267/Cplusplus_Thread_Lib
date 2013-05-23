

#include "CLinuxMsgQueue.h"
#include "COperatingSystemFactory.h"


CLinuxMsgQueue::CLinuxMsgQueue(const char *pName):
CMsgQueue(pName)
{

	p_mutex=COperatingSystemFactory::newMutex("Msg Mutex");
	p_sem=COperatingSystemFactory::newCountingSem(0);


}



CLinuxMsgQueue::~CLinuxMsgQueue()
{

}





bool CLinuxMsgQueue::recvMsg(unsigned int &m_msg_code,void *&p_msg)
{

 	bool result;
    	Elements queue_element;

	p_sem->Get();

	p_mutex->Lock();
   
	if (m_queue.empty()) {
	    
		p_mutex->UnLock();
	    	return false;
	    
	}


	queue_element = m_queue.front();
	m_queue.pop_front();


	m_msg_code = queue_element.msg_code;
	p_msg = queue_element.p_message;

	p_mutex->UnLock();

    return true;


}




bool CLinuxMsgQueue::sendMsg(unsigned int m_msg_code,void *p_msg)
{
	bool result;
    	Elements queue_element;

	

	queue_element.msg_code=m_msg_code;
	queue_element.p_message=p_msg;

	p_mutex->Lock();

	m_queue.push_back(queue_element);


	p_mutex->UnLock();

	p_sem->Post();


    return true;


}


