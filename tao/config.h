#ifndef __TAO_CONFIG_H__
#define __TAO_CONFIG_H__

#include<memory> //智能指针
#include<string>
#include<sstream> //序列化
#include<boost/lexical_cast.hpp> //内存转化
#include"log.h"

namespace{

class ConfigVarBase{
public:
    typedef std::shared_ptr<ConfigVarBase> ptr;
    ConfigVarBase(const std::string& name, const std::string& description)
        :m_name(name)
        ,m_description(description) {
    }
    virtual ~ConfigVarBase(){}

    const std::string& getName()const{  return m_name;}
    const std::string& getDescription() const {return m_description;}

    virtual std::string toString() = 0;
    virtual bool fromString(const std::string& val) = 0;
private:
    std::string m_name;
    std::string m_description;
};

template<class T>
class ConfigVar:public ConfigVarBase{
public:
    typedef std::shared_ptr<ConfigVar> ptr;

    ConfigVar(const std::string& name, const T& default_value, const std::string& description)
        :ConfigVarBase(name, description)
        ,m_val(default_value){
    }

    std::string toString() override {
        try
        {
        
        }
        catch(...)
        {
            std::cerr << e.what() << '\n';
        }
        
        return "";
    }

    bool fromString(const std::string& val) override {
        
    }
private:
    T m_val;
};

}

#endif