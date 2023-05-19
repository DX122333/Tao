#ifndef __TAO_UTIL_H__
#define __TAO_UTIL_H__

#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<stdio.h>
#include <vector>
#include <string>

namespace tao{
pid_t GetThreadId();

u_int32_t GetFiberId();

void Backtrace(std::vector<std::string>& bt, int size, int skip=1);

std::string BacktraceToString(int size, int skip=2, const std::string& prefix = "");

}

#endif