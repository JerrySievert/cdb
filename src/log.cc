#include <fstream>
#include <initializer_list>
#include <chrono>
#include <ctime>

#include "log.h"

string current_time ( ) {
  time_t t = time(NULL);
  char mbstr[100];
  strftime(mbstr, sizeof(mbstr), "%c", localtime(&t));

  return string(mbstr);
}

void write_log (ofstream& out_f, initializer_list<string> out) {
  int count = 1;

  out_f << current_time() << ": ";

  for (auto i : out) {
    out_f << i;

    if (out.size() > count) {
      out_f << " ";
    }

    count++;
  }

  out_f << endl;
  out_f.flush();
}

Logger::Logger (Config config) {
  error_f.open(config.logPath + "error.log", ofstream::out | ofstream::app);
  warn_f.open(config.logPath + "warn.log", ofstream::out | ofstream::app);
  debug_f.open(config.logPath + "debug.log", ofstream::out | ofstream::app);
  notice_f.open(config.logPath + "notice.log", ofstream::out | ofstream::app);
  log_f.open(config.logPath + "cdb.log", ofstream::out | ofstream::app);
}

void Logger::close ( ) {
  error_f.close();
  warn_f.close();
  debug_f.close();
  notice_f.close();
  log_f.close();
}

void Logger::error (initializer_list<string> out) {
  write_log(error_f, out);
}

void Logger::warn (initializer_list<string> out) {
  write_log(warn_f, out);
}

void Logger::debug (initializer_list<string> out) {
  write_log(debug_f, out);
}

void Logger::notice (initializer_list<string> out) {
  write_log(notice_f, out);
}

void Logger::log (initializer_list<string> out) {
  write_log(log_f, out);
}
