#pragma once

#include <fstream>
#include <initializer_list>
#include <stdint.h>

#include "config.h"

class Logger {
private:
  std::ofstream error_f;
  std::ofstream warn_f;
  std::ofstream debug_f;
  std::ofstream notice_f;
  std::ofstream log_f;
public:
  Logger (Config);
  void close ( );
  void error (std::initializer_list<std::string>);
  void warn (std::initializer_list<std::string>);
  void debug (std::initializer_list<std::string>);
  void notice (std::initializer_list<std::string>);
  void log (std::initializer_list<std::string>);
};
