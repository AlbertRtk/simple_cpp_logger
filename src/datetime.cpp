#include "datetime.h"

#include <chrono>

SCL_ULong datetime::GetTimestampNow() {
  auto now = std::chrono::system_clock::now();
  SCL_ULong output = now.time_since_epoch().count();
  return output;
}

SCL_String datetime::GetDateTimeNow() {
  auto now = std::chrono::system_clock::now();
  std::time_t time_now = std::chrono::system_clock::to_time_t(now);
  char buf[20];
  strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S\0", std::localtime(&time_now));
  SCL_String output = buf;
  return output;
}

SCL_String datetime::GetTimeNow() {
  auto now = std::chrono::system_clock::now();
  std::time_t time_now = std::chrono::system_clock::to_time_t(now);
  char buf[9];
  strftime(buf, sizeof(buf), "%H:%M:%S\0", std::localtime(&time_now));
  SCL_String output = buf;
  return output;
}
