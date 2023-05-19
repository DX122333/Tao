#include "../tao/tao.h"
#include <assert.h>

tao::Logger::ptr g_logger = TAO_LOG_ROOT();

void test_assert(){
    //std::string prefix = "   ";
    TAO_LOG_INFO(g_logger) << tao::BacktraceToString(10); 
    TAO_ASSERT(false)
}

int main(int argc, char** argv){
    test_assert();

    return 0;
}