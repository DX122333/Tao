#include "../tao/config.h"
#include "../tao/log.h"
#include "yaml-cpp/yaml.h"

tao::ConfigVar<int>::ptr g_int_value_config = tao::Config::Lookup("system.port", (int)8080, "system port");
tao::ConfigVar<float>::ptr g_float_value_config = tao::Config::Lookup("system.value", (float)10.2f, "system value");

tao::ConfigVar<std::vector<int> >::ptr g_int_vec_value_config = 
    tao::Config::Lookup("system.int_vec", std::vector<int>{1, 2}, "system int vec");

tao::ConfigVar<std::list<int> >::ptr g_int_list_value_config = 
    tao::Config::Lookup("system.int_list", std::list<int>{1, 2}, "system int list");

void print_yaml(const YAML::Node& node, int level){
    if(node.IsScalar()){
        TAO_LOG_INFO(TAO_LOG_ROOT())<<std::string(level * 4, ' ')
            <<node.Scalar()<<"-"<<node.Type()<<"-"<<level;
    }else if(node.IsNull()){
        TAO_LOG_INFO(TAO_LOG_ROOT())<<std::string(level * 4, ' ')
            <<"NULL - "<<node.Type()<<" - "<<level;
    }else if(node.IsMap()){
        for(auto it = node.begin();
                it != node.end(); ++it){
                    TAO_LOG_INFO(TAO_LOG_ROOT())<<std::string(level * 4, ' ')
                        <<it->first<<" - "<<it->second.Type()<<" - "<<level;
                    print_yaml(it->second, level+1);
                }
    }else if(node.IsSequence()){
        for(size_t i = 0; i<node.size(); ++i){
            TAO_LOG_INFO(TAO_LOG_ROOT())<<std::string(level * 4, ' ')
                <<i<<" - "<<node[i].Type()<<" - "<<level;
            print_yaml(node[i], level+1);
        }

    }
}


void test_yaml(){
    YAML::Node root = YAML::LoadFile("/home/nowcoder/Tao/bin/conf/log.yml");//加载yaml
    print_yaml(root, 0);

    TAO_LOG_INFO(TAO_LOG_ROOT())<<root.Scalar();
}

void test_config(){
    TAO_LOG_INFO(TAO_LOG_ROOT())<<"before: "<<g_int_value_config->getValue();
    TAO_LOG_INFO(TAO_LOG_ROOT())<<"before: "<<g_float_value_config->toString();

#define XX(g_var, name, prefix) \
    { \
        auto& v = g_var->getValue();\
        for(auto& i : v){ \
            TAO_LOG_INFO(TAO_LOG_ROOT()) << #prefix " " #name ": "<<i; \
        } \
    }

    XX(g_int_vec_value_config, int_vec, before);
    XX(g_int_list_value_config, int_list, before);

    YAML::Node root = YAML::LoadFile("/home/nowcoder/Tao/bin/conf/log.yml");
    tao::Config::LoadFromYaml(root);

    TAO_LOG_INFO(TAO_LOG_ROOT())<<"after: "<<g_int_value_config->getValue();
    TAO_LOG_INFO(TAO_LOG_ROOT())<<"after: "<<g_float_value_config->toString();

    XX(g_int_vec_value_config, int_vec, after);
    XX(g_int_list_value_config, int_list, after);
}

int main(int argc, char** argv){
    //TAO_LOG_INFO(TAO_LOG_ROOT()) << g_int_value_config->getValue();
    //TAO_LOG_INFO(TAO_LOG_ROOT()) << g_int_value_config->toString();

    //test_yaml();
    test_config();
    return 0;
}