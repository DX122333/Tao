#include "../tao/tao.h"
#include <unistd.h>

tao::Logger::ptr g_logger = TAO_LOG_ROOT();

int count = 0;
tao::RWMutex s_mutex;

void fun1(){
    TAO_LOG_INFO(g_logger)<<"name: "<<tao::Thread::GetName()
                                    <<" this.name: "<<tao::Thread::GetThis()->getName()
                                    <<" id: "<<tao::GetThreadId()
                                    <<" this.id: "<<tao::Thread::GetThis()->getId();
    
    for(int i=0; i<100000; ++i){
        tao::RWMutex::WriteLock lock(s_mutex);
        ++count;
    }
}

void fun2(){

}

int main(int argc, char** argv){
    TAO_LOG_INFO(g_logger)<<"thread test begin...";
    std::vector<tao::Thread::ptr> thrs;
    for(int i=0; i<5; ++i){
        tao::Thread::ptr thr(new tao::Thread(&fun1, "name_"+std::to_string(i)));
        thrs.push_back(thr);
    }

    for(int i=0; i<5; ++i){
        thrs[i]->join();
    }
    TAO_LOG_INFO(g_logger)<<"thread test end";
    TAO_LOG_INFO(g_logger)<<"count="<<count;
    return 0;
}