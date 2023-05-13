#include "../tao/tao.h"
#include <unistd.h>

tao::Logger::ptr g_logger = TAO_LOG_NAME("system");

int count = 0;
//tao::RWMutex s_mutex;
tao::Mutex s_mutex;

void fun1(){
    TAO_LOG_INFO(g_logger)<<"name: "<<tao::Thread::GetName()
                                    <<" this.name: "<<tao::Thread::GetThis()->getName()
                                    <<" id: "<<tao::GetThreadId()
                                    <<" this.id: "<<tao::Thread::GetThis()->getId();
    
    for(int i=0; i<100000; ++i){
        //tao::RWMutex::WriteLock lock(s_mutex);
        tao::Mutex::Lock lock(s_mutex);
        ++count;
    }
}

void fun2(){
    int cnt = 3;
    while(cnt){
        TAO_LOG_INFO(g_logger)<<"*************************";
        --cnt;
    }
}

void fun3(){
    int cnt = 3;
    while(cnt){
        TAO_LOG_INFO(g_logger)<<"==========================";
        --cnt;
    }
}

int main(int argc, char** argv){
    TAO_LOG_INFO(g_logger)<<"thread test begin...";

    YAML::Node system = YAML::LoadFile("/home/nowcoder/Tao/bin/conf/log2.yml");
    tao::Config::LoadFromYaml(system);

    std::vector<tao::Thread::ptr> thrs;
    for(int i=0; i<2; ++i){
        tao::Thread::ptr thr1(new tao::Thread(&fun2, "name_"+std::to_string(i*2)));
        tao::Thread::ptr thr2(new tao::Thread(&fun3, "name_"+std::to_string(i*2+1)));
        thrs.push_back(thr1);
        thrs.push_back(thr2);
    }

    for(size_t i=0; i<thrs.size(); ++i){
        thrs[i]->join();
    }
    TAO_LOG_INFO(g_logger)<<"thread test end";
    TAO_LOG_INFO(g_logger)<<"count="<<count;
    return 0;
}