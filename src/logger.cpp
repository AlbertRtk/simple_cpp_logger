#include "logger.h"

#include "datetime.h"

void scl::Logger::Log(const SCL_String& msg, const SCL_String& level, const SCL_String& file, int line,
                 const SCL_String& function) {
  std::ofstream log_file(log_file_path_, std::ios::out | std::ios::app);
  SCL_String level_and_msg =
      " [" + level + "]   File " + file + ", line " + std::to_string(line) + ", in " + function + ":   " + msg;
  if (log_file.is_open()) {
    log_file << datetime::GetDateTimeNow() << level_and_msg << std::endl;
    log_file.close();
  }
  if (IsVerbose()) {
    std::cout << datetime::GetTimeNow() << level_and_msg << std::endl;
  }
}

SCL_String scl::Logger::GetNewLogFileName() {
  SCL_String log_file_name = std::to_string(datetime::GetTimestampNow()) + ".log";
  return log_file_name;
}

void scl::Logger::LogInfo(const SCL_String& msg, const SCL_String& file, int line, const SCL_String& function) {
  Log(msg, "INFO   ", file, line, function);
}

void scl::Logger::LogDebug(const SCL_String& msg, const SCL_String& file, int line, const SCL_String& function) {
  Log(msg, "DEBUG  ", file, line, function);
}

void scl::Logger::LogWarning(const SCL_String& msg, const SCL_String& file, int line, const SCL_String& function) {
  Log(msg, "WARNING", file, line, function);
}

void scl::Logger::LogError(const SCL_String& msg, const SCL_String& file, int line, const SCL_String& function) {
  Log(msg, "ERROR  ", file, line, function);
}
