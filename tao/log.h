#ifndef __TAO_LOG_H
#define __TAO_LOG_H

#include<string>
#include<stdint.h>
#include<list>
#include<memory>
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<functional>
#include<time.h>
#include<string.h>
#include<stdarg.h>
#include<map>
#include "singleton.h"
#include "util.h"

/**
 * @brief 使用流式方式将日志级别level的日志写入到logger
 */
#define TAO_LOG_LEVEL(logger, level) \
    if(logger->getLevel() <= level) \
        tao::LogEventWrap(tao::LogEvent::ptr(new tao::LogEvent(logger, level, \
                        __FILE__, __LINE__, 0, tao::GetThreadId(),\
                tao::GetFiberId(), time(0), ""))).getSS()
 
/**
 * @brief 使用流式方式将日志级别debug的日志写入到logger
 */
#define TAO_LOG_DEBUG(logger) TAO_LOG_LEVEL(logger, tao::LogLevel::DEBUG)

/**
 * @brief 使用流式方式将日志级别info的日志写入到logger
 */
#define TAO_LOG_INFO(logger) TAO_LOG_LEVEL(logger, tao::LogLevel::INFO)

/**
 * @brief 使用流式方式将日志级别warn的日志写入到logger
 */
#define TAO_LOG_WARN(logger) TAO_LOG_LEVEL(logger, tao::LogLevel::WARN)

/**
 * @brief 使用流式方式将日志级别error的日志写入到logger
 */
#define TAO_LOG_ERROR(logger) TAO_LOG_LEVEL(logger, tao::LogLevel::ERROR)

/**
 * @brief 使用流式方式将日志级别fatal的日志写入到logger
 */
#define TAO_LOG_FATAL(logger) TAO_LOG_LEVEL(logger, tao::LogLevel::FATAL)


/**
 * @brief 使用格式化方式将日志级别level的日志写入到logger
 */
#define TAO_LOG_FMT_LEVEL(logger, level, fmt, ...) \
    if(logger->getLevel() <= level) \
        tao::LogEventWrap(tao::LogEvent::ptr(new tao::LogEvent(logger, level, \
                        __FILE__, __LINE__, 0, tao::GetThreadId(),\
                tao::GetFiberId(), time(0), ""))).getEvent()->format(fmt, __VA_ARGS__)

/**
 * @brief 使用格式化方式将日志级别debug的日志写入到logger
 */
#define TAO_LOG_FMT_DEBUG(logger, fmt, ...) TAO_LOG_FMT_LEVEL(logger, tao::LogLevel::DEBUG, fmt, __VA_ARGS__)

/**
 * @brief 使用格式化方式将日志级别info的日志写入到logger
 */
#define TAO_LOG_FMT_INFO(logger, fmt, ...)  TAO_LOG_FMT_LEVEL(logger, tao::LogLevel::INFO, fmt, __VA_ARGS__)

/**
 * @brief 使用格式化方式将日志级别warn的日志写入到logger
 */
#define TAO_LOG_FMT_WARN(logger, fmt, ...)  TAO_LOG_FMT_LEVEL(logger, tao::LogLevel::WARN, fmt, __VA_ARGS__)

/**
 * @brief 使用格式化方式将日志级别error的日志写入到logger
 */
#define TAO_LOG_FMT_ERROR(logger, fmt, ...) TAO_LOG_FMT_LEVEL(logger, tao::LogLevel::ERROR, fmt, __VA_ARGS__)

/**
 * @brief 使用格式化方式将日志级别fatal的日志写入到logger
 */
#define TAO_LOG_FMT_FATAL(logger, fmt, ...) TAO_LOG_FMT_LEVEL(logger, tao::LogLevel::FATAL, fmt, __VA_ARGS__)

/**
 * @brief 获取主日志器
 */
#define TAO_LOG_ROOT() tao::LoggerMgr::GetInstance()->getRoot()

/**
 * @brief 获取name的日志器
 */
#define TAO_LOG_NAME(name) tao::LoggerMgr::GetInstance()->getLogger(name)


namespace tao{

class Logger;
class LoggerManager;

//日志级别
class LogLevel{
public:
    enum Level{
        UNKNOW = 0,
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5
    };

    static const char* ToString(LogLevel::Level level);
    static LogLevel::Level FromString(const std::string& str);
};

//日志事件
class LogEvent{
public:
    typedef std::shared_ptr<LogEvent> ptr;
    //LogEvent(const char* file, int32_t line, uint32_t elapse, uint32_t thread_id, uint32_t fiber_id, u_int64_t time);
    LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level
            ,const char* file, int32_t line, uint32_t elapse
            ,uint32_t thread_id, uint32_t fiber_id, uint64_t time
            ,const std::string& thread_name);
    ~LogEvent();
    
    const char* getFile()const{return m_file;}
    int32_t getLine()const{return m_line;}
    uint32_t getElapse()const{return m_elapse;}
    uint32_t getThreadId()const{return m_threadId;}
    uint32_t getFiberId()const{return m_fiberId;}
    uint64_t getTime()const{return m_time;}
    std::string getContent()const{return m_ss.str();}
    std::stringstream& getSS(){return m_ss;}
    void format(const char* fmt, ...);
    void format(const char* fmt, va_list al);
    /**
     * @brief 返回日志器
     */
    std::shared_ptr<Logger> getLogger() const { return m_logger;}
    /**
     * @brief 返回日志级别
     */
    LogLevel::Level getLevel()const{return m_level;}
    /**
     * @brief 返回线程名称
     */
    const std::string& getThreadName() const { return m_threadName;}
private:
    const char* m_file = nullptr; //文件名
    int32_t m_line = 0;           //行号
    uint32_t m_elapse = 0;        //程序启动开始到现在的毫秒数
    uint32_t m_threadId = 0;      //线程号
    uint32_t m_fiberId = 0;       //协程号
    uint64_t m_time = 0;          //时间戳
    std::stringstream m_ss;        //文件内容
    std::shared_ptr<Logger> m_logger;
    LogLevel::Level m_level;
    std::string m_threadName;
};

class LogEventWrap {
public:
    LogEventWrap(LogEvent::ptr e);
    ~LogEventWrap();

    std::stringstream& getSS();
    LogEvent::ptr getEvent(){return m_event;}
private:
    LogEvent::ptr m_event;
};

//日志格式器
class LogFormatter{
public:
    typedef std::shared_ptr<LogFormatter> ptr;
    //用于解析pattern
    LogFormatter(const std::string& pattern);
    std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
public:
    class FormatItem{
    public:
        typedef std::shared_ptr<FormatItem> ptr;
        FormatItem(const std::string& fmt = ""){};
        virtual ~FormatItem(){}
        virtual void format(std::ostream& os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event)=0;
    };
    void init();
    bool isError() const { return m_error; }
private:
    std::string m_pattern;
    std::vector<FormatItem::ptr> m_items;
    bool m_error = false;
};

//日志输出地
class LogAppender{
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender(){}
    virtual void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event)=0; //纯虚函数，子类必须要实现这个方法

    void setFormatter(LogFormatter::ptr val){m_formatter = val;}
    LogFormatter::ptr getFormatter() const {return m_formatter;}
    LogLevel::Level getLevel() const {return m_level;}
    void setLevel(LogLevel::Level val) {m_level = val;}
protected:
    LogLevel::Level m_level = LogLevel::DEBUG;
    LogFormatter::ptr m_formatter;
};

//日志器
class Logger:public std::enable_shared_from_this<Logger>{
friend class LoggerManager;
public:
    typedef std::shared_ptr<Logger> ptr;
    
    Logger(const std::string& name = "root");

    void log(LogLevel::Level level, LogEvent::ptr event);
    void debug(LogEvent::ptr event);
    void info(LogEvent::ptr event);
    void warn(LogEvent::ptr event);
    void error(LogEvent::ptr event);
    void fatal(LogEvent::ptr event);

    void addAppender(LogAppender::ptr);
    void delAppender(LogAppender::ptr);
    void clearAppenders();

    LogLevel::Level getLevel()const{return m_level;}
    void setLevel(LogLevel::Level val){m_level = val;}

    const std::string& getName()const{return m_name;}

    void setFormatter(LogFormatter::ptr val);
    void setFormatter(const std::string& val);
    LogFormatter::ptr getFormatter();
private:
    std::string m_name;             //日志名称
    LogLevel::Level m_level;        //日志级别，只有满足日志级别的才会被输出
    std::list<LogAppender::ptr> m_appenders; //Appender集合
    LogFormatter::ptr m_formatter;
    Logger::ptr m_root;
};

//输出到控制台的Appender
class StdoutLogAppender: public LogAppender{
public:
    typedef std::shared_ptr<StdoutLogAppender> ptr;
    virtual void log(Logger::ptr logger, LogLevel::Level level, LogEvent::ptr event) override;
private: 

};

//定义输出到文件的Appender
class FileLogAppender: public LogAppender{
public:
    typedef std::shared_ptr<FileLogAppender> ptr;
    FileLogAppender(){}
    FileLogAppender(const std::string& filename);
    virtual void log(Logger::ptr logger, LogLevel::Level level, LogEvent::ptr event) override;
    bool reopen();
private:
    std::string m_filename;
    std::ofstream m_filestream;
};

class LoggerManager{
public:
    LoggerManager();
    Logger::ptr getLogger(const std::string& name);

    void init();
    Logger::ptr getRoot() const {return m_root;}
private:
    std::map<std::string, Logger::ptr> m_loggers;
    Logger::ptr m_root;
};
typedef tao::Singleton<LoggerManager> LoggerMgr;
}

#endif