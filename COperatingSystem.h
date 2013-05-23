


#ifndef _COperatingSystem_H_
#define _COperatingSystem_H_

/********************************************************************************************
*
*File name: COperatingSystem.h
*Author: Wu Yinghao
*Version: 0.0.1
*Date: 2013.5.20
*E-Mail: wyh817@gmail.com
*Description: this file is base class of OSs
*
********************************************************************************************/

class CThread;


class COperatingSystem
{
	public:
		COperatingSystem();
		~COperatingSystem();


		//create thread
		virtual  bool createThread(CThread *mThread,unsigned long stack_size=8*1024)=0;

		//system sleep function
		virtual void  sleepSec(unsigned long sec)=0;


	protected:

		CThread		*p_thread;


};



#endif


