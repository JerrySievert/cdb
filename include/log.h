#pragma once

#include <fstream>
#include <initializer_list>
#include <stdint.h>

#include "config.h"

using namespace std;

class Logger {
private:
  ofstream error_f;
  ofstream warn_f;
  ofstream debug_f;
  ofstream notice_f;
  ofstream log_f;
public:
  Logger (Config);
  void close ( );
  void error (initializer_list<string>);
  void warn (initializer_list<string>);
  void debug (initializer_list<string>);
  void notice (initializer_list<string>);
  void log (initializer_list<string>);
};
