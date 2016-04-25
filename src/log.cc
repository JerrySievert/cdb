#include <fstream>
#include <initializer_list>
#include <chrono>
#include <ctime>

#include "log.h"

std::string current_time ( ) {
  std::time_t t = std::time(NULL);
  char mbstr[100];
  std::strftime(mbstr, sizeof(mbstr), "%c", std::localtime(&t));

  return std::string(mbstr);
}

void write_log (std::ofstream& out_f, std::initializer_list<std::string> out) {
  int count = 1;

  out_f << current_time() << ": ";

  for (auto i : out) {
    out_f << i;

    if (out.size() > count) {
      out_f << " ";
    }

    count++;
  }

  out_f << std::endl;
  out_f.flush();
}

Logger::Logger (Config config) {
  error_f.open(config.logPath + "error.log", std::ofstream::out | std::ofstream::app);
  warn_f.open(config.logPath + "warn.log", std::ofstream::out | std::ofstream::app);
  debug_f.open(config.logPath + "debug.log", std::ofstream::out | std::ofstream::app);
  notice_f.open(config.logPath + "notice.log", std::ofstream::out | std::ofstream::app);
  log_f.open(config.logPath + "cdb.log", std::ofstream::out | std::ofstream::app);
}

void Logger::close ( ) {
  error_f.close();
  warn_f.close();
  debug_f.close();
  notice_f.close();
  log_f.close();
}

void Logger::error (std::initializer_list<std::string> out) {
  write_log(error_f, out);
}

void Logger::warn (std::initializer_list<std::string> out) {
  write_log(warn_f, out);
}

void Logger::debug (std::initializer_list<std::string> out) {
  write_log(debug_f, out);
}

void Logger::notice (std::initializer_list<std::string> out) {
  write_log(notice_f, out);
}

void Logger::log (std::initializer_list<std::string> out) {
  write_log(log_f, out);
}
