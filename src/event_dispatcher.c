/*
 * =====================================================================================
 *
 *       Filename:  event_dispatcher.c
 *
 *    Description:  事件分发器的
 *
 *        Version:  1.0
 *        Created:  07/23/2015 17:51:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ran Zhang
 *        Company:  
 *
 * =====================================================================================
 */
#include <libcu.h>

#define EVENTDISP_NUM 128

struct event_handle_t{
    char event_name[32];
    void *handle;
    unsigned int event_type;
    event_handle_func func;
};

typedef struct event_handle_t event_handle;

struct event_dispatcher_t{
    void * event_queue_handle;
    event_handle handle[EVENTDISP_NUM];
    int handle_num;
    bool enable;
};
typedef struct event_dispatcher_t event_dispatcher;

int (*event_handle_func)(void* handler, void* event);
int (*event_queue_pop_func)(void* handler, void* event, int timeout);

event_dispatcher event_dispatcher_init(void* queue_handle){
    event_dispatcher *pdispatcher = (event_dispatcher *)malloc(struct event_dispatcher_t);
    pdispatcher.event_queue_handle = queue_handle;
    pdispatcher.enable = FLASE;
    pdispatcher.handle_num = 0;

    return pdispatcher;

}

event_dispatcher_destroy(event_dispatcher ev_dispatcher){
    if(ev_dispatcher)
        free(ev_dispatcher);
    ev_dispatcher = NULL;
}

event_dispatcher_register_handler(event_dispatcher *ev_dispatcher, char *event_name, unsigned int event_type, event_handle_func event_func, void* handle){
    //需要处理一下相同event_type的事件怎么办
    event_handle *p_handle = &(ev_dispatcher->handle[ev_dispatcher.handle_num]);
    strcpy(p_handle->event_name, event_name);
    p_handle->event_type = event_type;
    p_handle->func = event_func;
    p_handle->handle = handle;

    ev_dispatcher.handle_num++;
}

event_dispatcher_unregister_handler(event_dispatcher ev_dispatcher, char *event_name){

}

event_diapatcher_loop(){
    //循环获取queue中的事件,并进行事件消息的分发

}

event_dispatcher_do_event(event_dispatcher ev_dispatcher, void* event){

    //需要处理一下相同event_type的事件怎么办

}

event_diapatcher_enable(){

}


