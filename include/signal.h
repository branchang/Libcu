/*
 * =====================================================================================
 *
 *       Filename:  signal.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/23/2015 22:07:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <libcu.h>
#include <semaphore.h>
#ifndef _CU_SIGNAL_H_
#define _CU_SIGNAL_H_

#ifdef  __cpluspuls
extern "C"
{
#endif

struct cu_signal_t{
    sem_t *sem;
    char sem_name[256];
    int max_value;
};
typedef struct cu_signal_t cu_signal;

HANDLE signal_create(const char *name, int default_value, int max_value);

HANDLE signal_close(HANDLE psignal);

int signal_timewait(HANDLE psignal, int time);

int signal_post(HANDLE psignal);

#ifdef  __cpluspuls
}
#endif

#endif 
