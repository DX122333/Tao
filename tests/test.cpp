#include<iostream>
#include "../tao/log.h"
#include "../tao/util.h"

int main() {
    tao::Logger::ptr logger(new tao::Logger("firstLogger"));

    tao::LogFormatter::ptr fmt(new tao::LogFormatter("%d%T%m%n"));
    tao::FileLogAppender::ptr file_appender(new tao::FileLogAppender("./out_of_fileappender_log.txt"));
    file_appender->setFormatter(fmt);

    //logger->addAppender(tao::LogAppender::ptr(new tao::StdoutLogAppender));
    logger->addAppender(file_appender);

    tao::LogEvent::ptr event(new tao::LogEvent(logger,tao::LogLevel::Level::DEBUG ,__FILE__, __LINE__, 0, tao::GetThreadId(), tao::GetFiberId(), time(0), "firstThread"));

    logger->log(tao::LogLevel::DEBUG, event);
    //std::cout<<"hello tao log"<<std::endl;

    TAO_LOG_INFO(logger)<<"test macro!"<<std::endl;
    TAO_LOG_ERROR(logger)<<"test macro error"<<std::endl;
    TAO_LOG_FMT_ERROR(logger, "test macro error %s", "aa");

    auto l = tao::LoggerMgr::GetInstance()->getLogger("xx");
    TAO_LOG_INFO(l)<<"xxx";
    return 0;
}