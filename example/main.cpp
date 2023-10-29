#include "logger.h"

int main(int argc, char *argv[]) {
    scl::Logger::GetLogger().Initialize("my_log_file.log");
    scl::Logger::GetLogger().MakeVerbose();
    LOG_INFO("Logger started...");
    LOG_DEBUG("Debug message.");
    LOG_WARNING("Warning message!");
    LOG_ERROR("ERROR MESSAGE!!!");
    return 0;
}