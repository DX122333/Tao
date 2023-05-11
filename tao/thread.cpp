#include "thread.h"
#include "log.h"
#include "util.h"

namespace tao{

static thread_local Thread* t_thread = nullptr;
static thread_local std::string t_thread_name = "UNKNOW";

//线程相关日志统一交给system日志器处理
static tao::Logger::ptr g_logger = TAO_LOG_NAME("system");

Thread* Thread::GetThis(){
    return t_thread;
}

//与日志系统有关
const std::string Thread::GetName(){
    return t_thread_name;
}

void Thread::SetName(const std::string& name){
    if(t_thread){
        t_thread->m_name = name;
    }
    t_thread_name = name;
}

Thread::Thread(std::function<void()> cb, const std::string& name)
    :m_cb(cb)
    ,m_name(name){
    if(name.empty()){
        m_name = "UNKNOW";
    }
    int rt = pthread_create(&m_thread, nullptr, &Thread::run, this);
    if(rt){
        TAO_LOG_ERROR(g_logger)<<"pthread_create thread fail, rt="<<rt<<" name="<<name;
        throw std::logic_error("pthread_create error");
    }
}
Thread::~Thread(){
    if(m_thread){
        pthread_detach(m_thread);
    }
}

void* Thread::run(void* arg){
    Thread* thread = (Thread*)arg;
    t_thread = thread;
    thread->m_id = tao::GetThreadId();
    pthread_setname_np(pthread_self(), thread->m_name.substr(0,15).c_str());

    std::function<void()> cb;
    cb.swap(thread->m_cb);

    cb();
    return 0;
}
void Thread::join(){
    if(m_thread){
        int rt = pthread_join(m_thread, nullptr);
        if(rt){
            TAO_LOG_ERROR(g_logger)<<"pthread_join thread fail, rt="<<rt<<" name="<<m_name;
            throw std::logic_error("pthread_join error");
        }
        m_thread = 0;
    }
}
}