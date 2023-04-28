#include "../tao/config.h"
#include "../tao/log.h"

tao::ConfigVar<int>::ptr g_int_value_config = tao::Config::Lookup("system.port", (int)8080, "system port");

int main(int argc, char** argv){
    TAO_LOG_INFO(TAO_LOG_ROOT()) << g_int_value_config->getValue();
    TAO_LOG_INFO(TAO_LOG_ROOT()) << g_int_value_config->toString();
    return 0;
}