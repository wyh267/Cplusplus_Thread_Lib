

#ifndef _CTHREAD_H_
#define _CTHREAD_H_

/********************************************************************************************
*
*File name: CThread.h
*Author: Wu Yinghao
*Version: 0.0.1
*Date: 2013.5.20
*E-Mail: wyh817@gmail.com
*Description: this file is base class of threads
*
********************************************************************************************/

#include "COperatingSystem.h"
#include "CCountingSem.h"

class CThread
{
	public:
		CThread(const char *m_thread_name);

		~CThread();

		 //Thread Entry
		 void threadEntry(CCountingSem *pSemaphore);

		 //the thread will be run if you call this function
		 bool run();


	protected:

		/*********************************************************
		*
		*	init the thread informations
		*	input: none
		*	output: true if success 
		*
		**********************************************************/
		 bool initializeThread();


		/*********************************************************
		*
		*	
		*	
		*	
		*
		**********************************************************/
		virtual void mainLoop()=0;

		

		COperatingSystem		*p_opration_system;

		char		*p_thread_name;


		



};















#endif






