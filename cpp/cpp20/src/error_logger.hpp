#ifndef ERROR_LOGGER_HPP
#define ERROR_LOGGER_HPP

#include <iostream>
#include <string>

class ErrorLogger
{
public:
  static void log(const std::string &message)
  {
    std::cerr << "エラー: " << message << '\n';
  }
};

#endif // ERROR_LOGGER_HPP
