/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  队列的实现
 *
 *        Version:  1.0
 *        Created:  10/20/2013 12:34:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct _Queue
{
    DList* dlist;
}Queue;

Queue* queue_create(DataDestroyFunc data_destroy, void* ctx);
//获取队列头的元素
int queue_head(Queue* thiz, void **data);
int queue_push(Queue* thiz, void* data);
int queue_pop(Queue* thiz);
int queue_length(Queue* thiz);
void queue_foreach(Queue* thiz, DataVisitFunc visit, void* ctx);
int queue_destroy();

#endif
