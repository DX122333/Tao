#include "thread.h"

namespace tao{
Thread::Thread(std::function<void()> cb, const std::string& name){

}
Thread::~Thread(){

}

void Thread::join(){}
Thread* Thread::getThis(){}

//与日志系统有关
const std::string Thread::GetName(){}

}