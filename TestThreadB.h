

#ifndef _Test_thread_b_h_
#define _Test_thread_b_h_


#include "CThread.h"
#include "CMsgQueue.h"
#include "TestThread.h"

class TestThreadB:public CThread
{

	public:
		TestThreadB(const char *m_name);
		~TestThreadB();

		virtual void mainLoop();

		void setMsgQueue(CMsgQueue *q);

	private:

		CMsgQueue *p_msg_send;


};




#endif

