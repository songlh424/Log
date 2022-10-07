#include "printLog.h"

static char* EM_LogLevelGet(const int level) {
    if(level == LOG_DEBUG) {
        return "DEBUG";
    } else if(level == LOG_INFO) {
        return "INFO";
    } else if(level == LOG_WARN) {
        return "WARN";
    } else if(level == LOG_ERROR) {
        return "ERROR";
    }
    return "UNKNOW";
}


void EM_LOG(const int level, const char*file, const int line, const char* fmt, ...) {
    #ifdef OPEN_LOG
    va_list arg;
    va_start(arg, fmt);
    char buf[vsnprintf(NULL, 0, fmt, arg) + 1];
    vsnprintf(buf, sizeof(buf), fmt, arg);
    va_end(arg);
    if(level >= LOG_LEVEL)
        printf("[%s][%s %d] %s\n", EM_LogLevelGet(level), file, line, buf);

    // TODO存储
    #endif
}

// 测试
// void main()
// {
//     int a = 10;
//     EMLog(LOG_WARN, "a = %d", a);
// }