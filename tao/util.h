#ifndef __TAO_UTIL_H__
#define __TAO_UTIL_H__

#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<stdio.h>

namespace tao{
pid_t GetThreadId();

u_int32_t GetFiberId();
}

#endif