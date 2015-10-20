/*
 * =====================================================================================
 *
 *       Filename:  misc.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/19/2015 16:55:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef _CU_MISC_H_
#define _CU_MISC_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif 

int cu_isblank(int c);
int cu_isblank_str(const char *str);
int cu_isnl(int c);
    
#ifdef __cplusplus
}
#endif 

#endif 

