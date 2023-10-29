#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <iostream>
#include <string>

#include "scl_types.h"

#define LOG_INFO(msg) scl::Logger::GetLogger().LogInfo(msg, __FILE__, __LINE__, __func__)

#ifndef NDEBUG
#define LOG_DEBUG(msg) scl::Logger::GetLogger().LogDebug(msg, __FILE__, __LINE__, __func__)
#else
#define LOG_DEBUG(msg)
#endif

#define LOG_WARNING(msg) scl::Logger::GetLogger().LogWarning(msg, __FILE__, __LINE__, __func__)

#define LOG_ERROR(msg) scl::Logger::GetLogger().LogError(msg, __FILE__, __LINE__, __func__)

namespace scl {
class Logger {
 private:
  SCL_String log_file_path_;

  bool is_verbose_;

  Logger() : is_verbose_(false), log_file_path_(""){};

  ~Logger() = default;

  Logger(const Logger&) = default;

  Logger& operator=(const Logger&) = default;

  void Log(const SCL_String& msg, const SCL_String& level, const SCL_String& file, int line, const SCL_String& function);

 public:
  static Logger& GetLogger() {
    static Logger instance_;
    return instance_;
  }

  void Initialize(const SCL_String& log_path) { log_file_path_ = log_path; }

  void LogInfo(const SCL_String& msg, const SCL_String& file, int line, const SCL_String& function);

  void LogDebug(const SCL_String& msg, const SCL_String& file, int line, const SCL_String& function);

  void LogWarning(const SCL_String& msg, const SCL_String& file, int line, const SCL_String& function);

  void LogError(const SCL_String& msg, const SCL_String& file, int line, const SCL_String& function);

  static SCL_String GetNewLogFileName();

  void MakeVerbose() { is_verbose_ = true; }

  void MakeSilent() { is_verbose_ = false; }

  bool IsVerbose() { return is_verbose_; }
};
}

#endif  // LOGGER_H
