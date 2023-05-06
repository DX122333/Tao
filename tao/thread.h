#ifndef __TAO_THREAD_H__
#define __TAO_THREAD_H__

#include <thread>
#include <pthread.h>
#include <functional>
#include <memory>
#include <sys/types.h>
#include <bits/types.h>

//线程用c++11的std::thread, 读写锁用pthread
namespace tao{

class Thread{
public:
    typedef std::shared_ptr<Thread> ptr;
    Thread(std::function<void()> cb, const std::string& name);
    ~Thread();

    pid_t getId() const { return m_id;}
    const std::string& getName() const { return m_name;}

    void join();
    static Thread* getThis();

    //与日志系统有关
    static const std::string GetName();
private:
    Thread(const Thread&) = delete;
    Thread(const Thread&&) = delete;
    Thread& operator=(const Thread&) = delete;
private:
    pid_t m_id;
    pthread_t m_thread;
    std::function<void()> m_cb;
    std::string m_name;
};


}

#endif