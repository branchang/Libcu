/*
 * =====================================================================================
 *
 *       Filename:  signal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/25/2015 15:47:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <signal.h>

HANDLE signal_create(const char *name, int default_value, int max_value)
{
    cu_signal *signal = (cu_signal *)mallco(sizeof(cu_signal));
    if(!signal)
    {
        return NULL;
    }
    memset((void *)signal, 0, sizeof(cu_signal));
    int ret = 0;

    if(name)
    {
        int flags = O_CREAT|O_EXCL;
        ret = sem_open(name, flags, FILE_MODE, default_value);
        strlcpy(signal->sem_name, name, strlen(name));
    }else{
        ret = sem_init(signal->sem, 0, default_value);
    }

    if(ret==SEM_FAILED || ret == -1)
    {
        return NULL;
    }

    return signal;
}

HANDLE signal_close(HANDLE psignal)
{
    cu_signal *signal = (cu_signal *)psignal; 

    if(!signal->sem_name)
    {
        sem_destroy(signal);
    }

    if(signal->sem && signal->sem_name)
    {
        sem_close(signal->sem);
        sem_unlink(signal->sem);
    }

    free(signal);
}

int signal_timewait(HANDLE psignal, int time)
{
    if(psignal == NULL)
    {
        return -1;
    }
    
    cu_signal *signal = (cu_signal *)psignal;
    if(time < 0)
    {
        return sem_wait(signal->sem);
    }else
    {
        return 0;
    }
}

int signal_post(HANDLE psignal)
{
    if(psignal == NULL)
    {
        return -1;
    }

    cu_signal *signal = (cu_signal *)psignal;
    int valp = 0;
    sem_getvalue(signal->sem, &valp);
    if(valp<signal->max_value)
    {
        sem_post(signal->sem);
    }
    return 0;
}
