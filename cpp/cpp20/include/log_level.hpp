// log_level.hpp
#ifndef LOG_LEVEL_HPP
#define LOG_LEVEL_HPP

#include <string_view>

enum class LogLevel
{
  DEBUG,
  INFO,
  WARNING,
  ERROR
};

class LogLevelUtils
{
public:
  static constexpr std::string_view toString(LogLevel level)
  {
    switch (level)
    {
    case LogLevel::DEBUG:
      return "DEBUG";
    case LogLevel::INFO:
      return "INFO";
    case LogLevel::WARNING:
      return "WARNING";
    case LogLevel::ERROR:
      return "ERROR";
    }
    return "UNKNOWN";
  }

  static constexpr int toInt(LogLevel level)
  {
    return static_cast<int>(level);
  }
};

#endif // LOG_LEVEL_HPP
