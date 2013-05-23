

#ifndef _CMutex_H_
#define _CMutex_H_
#include <stdio.h>

/********************************************************************************************
*
*File name: CMutex.h
*Author: Wu Yinghao
*Version: 0.0.1
*Date: 2013.5.20
*E-Mail: wyh817@gmail.com
*Description: this file is base class of CMutexs
*
********************************************************************************************/


class CMutex
{

	public:
		CMutex(const char *pName = NULL);
		~CMutex();


		//Lock Mutex
		virtual bool Lock()=0;
		
		//Release Mutex
		virtual bool UnLock()=0;


		const char * getName(void) const {
        		return mutex_name;
    		}

	protected:

		char	   *mutex_name;


		





};






#endif


