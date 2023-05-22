#include "../tao/tao.h"

tao::Logger::ptr g_logger = TAO_LOG_ROOT();

void run_in_fiber(){
    TAO_LOG_INFO(g_logger)<<"run_in_fiber begin";
    tao::Fiber::YieldToHold();
    TAO_LOG_INFO(g_logger)<<"run_in_fiber end";
    tao::Fiber::YieldToHold();
}

int main(int agrc, char** argv){
    TAO_LOG_INFO(g_logger)<<"main begin -1";
    {
        tao::Fiber::GetThis();
        TAO_LOG_INFO(g_logger)<<"main begin";
        tao::Fiber::ptr fiber(new tao::Fiber(run_in_fiber));
        fiber->swapIn();
        TAO_LOG_INFO(g_logger)<<"main after swapIn";
        fiber->swapIn();
        TAO_LOG_INFO(g_logger)<<"main after end";
        fiber->swapIn();
    }
    TAO_LOG_INFO(g_logger)<<"main after end2";
    return 0;
}