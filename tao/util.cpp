#include "util.h"
#include <execinfo.h>

#include "log.h"

namespace tao{

tao::Logger::ptr g_logger = TAO_LOG_NAME("system");

pid_t GetThreadId(){
    return syscall(SYS_gettid);
}

u_int32_t GetFiberId(){
    return 0;
}

void Backtrace(std::vector<std::string>& bt, int size, int skip){
    void** array = (void**)malloc(sizeof(void*) * size); //指针数组，用于存储栈的size层的数据
    size_t s = ::backtrace(array, size);

    char** strings = backtrace_symbols(array, s);
    if(strings == NULL){
        TAO_LOG_ERROR(g_logger)<<"bakctrace_symbols error";
        return;
    }

    for(size_t i = skip; i < s; ++i){
        bt.push_back(strings[i]);
    }

    free(strings);
    free(array);
}

std::string BacktraceToString(int size, int skip, const std::string& prefix){
    std::vector<std::string> bt;
    Backtrace(bt, size, skip);
    std::stringstream ss;
    for(size_t i = 0; i < bt.size(); ++i){
        ss << prefix << bt[i] << std::endl;
    }

    return ss.str();
}

}