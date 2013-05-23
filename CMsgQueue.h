

#ifndef _CMsgQueue_H_
#define _CMsgQueue_H_

/********************************************************************************************
*
*File name: CMsgQueue.h
*Author: Wu Yinghao
*Version: 0.0.1
*Date: 2013.5.20
*E-Mail: wyh817@gmail.com
*Description: this file is base class of msgqueues
*
********************************************************************************************/


#include <stdio.h>


typedef struct {
    unsigned int        msg_code;
    void                   *p_message;
} Elements;




class CMsgQueue
{
	public:
		CMsgQueue(const char *pName=NULL);
		~CMsgQueue();


		//revice data from message queue
		virtual bool recvMsg(unsigned int &m_msg_code,void *&p_msg)=0;
		//send data to message queue
		virtual bool sendMsg(unsigned int m_msg_code,void *p_msg)=0;



		const char * getName(void) const {
        		return msg_queue_name;
    		}
		
	private:
		char *msg_queue_name;


};






#endif


