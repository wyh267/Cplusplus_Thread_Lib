

#ifndef _CLinuxMsg_h_
#define _CLinuxMsg_h_
#include <deque>
#include "CMsgQueue.h"
#include "CMutex.h"
#include "CCountingSem.h"


class CLinuxMsgQueue : public CMsgQueue
{
	public:
		CLinuxMsgQueue(const char *pName=NULL);
		~CLinuxMsgQueue();

		virtual bool recvMsg(unsigned int &m_msg_code,void *&p_msg);
		virtual bool sendMsg(unsigned int m_msg_code,void *p_msg);

	private:

		 std::deque<Elements>            m_queue;

		 
		CMutex	*p_mutex;
		CCountingSem *p_sem;

};










#endif



