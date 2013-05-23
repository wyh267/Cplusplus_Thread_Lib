
#ifndef _TestThread_h_
#define _TestThread_h_


#include "CThread.h"
#include "CMsgQueue.h"

class TestThread:public CThread
{

	public:
		TestThread(const char *m_name);
		~TestThread();

		virtual void mainLoop();


		void setMsgQueue(CMsgQueue *q);
		
	private:
		CMsgQueue *p_msg_rev;

		
		

};





#endif

