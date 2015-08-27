/*
 * =====================================================================================
 *
 *       Filename:  event_dispatcher.h
 *
 *    Description:  事件分发器的左右 
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
    event_handle[EVENTDISP_NUM];
    int handle_num;
    bool enable;
};
typedef struct event_dispatcher_t event_dispatcher;

int (*event_handle_func)(void* handler, void* event);
int (*event_queue_pop_func)(void* handler, void* event, int timeout);

event_dispatcher event_dispatcher_init(void* queue_handle);

event_dispatcher_destroy(event_dispatcher ev_dispatcher);

event_dispatcher_register_handler(event_dispatcher ev_dispatcher, char *event_name, unsigned int event_type, event_handle_func event_func, void* handle);

event_dispatcher_unregister_handler(event_dispatcher ev_dispatcher, char *event_name);

event_diapatcher_loop();

event_dispatcher_do_event(event_dispatcher ev_dispatcher, void* event);

event_diapatcher_enable();


