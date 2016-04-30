#include <fstream>
#include <streambuf>
#include <string>
#include <cerrno>
#include <cstdio>
#include <iostream>
#include <vector>

#include "log.h"
#include "config.h"
#include "util.h"
#include "test.h"

std::string get_file_contents(const char *filename) {
  std::ifstream ifs (filename, std::ifstream::in);
  char c, d[2];
  std::string read;

  c = ifs.get();

  while (ifs.good()) {
    d[0] = c;
    d[1] = '\0';

    read.append(d);
    c = ifs.get();
  }

  return read;

  throw(errno);
}

void cleanup ( ) {
  std::remove("./error.log");
  std::remove("./cdb.log");
  std::remove("./debug.log");
  std::remove("./notice.log");
  std::remove("./warn.log");
}

void test_error_log_single ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.error({"foo"});
  logger.close();

  std::string read = get_file_contents("./error.log");
  std::vector<std::string> parts = split(read, ':');
  check(parts[3] == " foo\n", "error file is correct for a single argument");

  cleanup();
}

void test_error_log_multi ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.error({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./error.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo bar\n", "error file is correct for multiple arguments");

  cleanup();
}

void test_error_log_append ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.error({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./error.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo bar\n", "error file is correct for append first read");

  Logger logger2(config);
  logger2.error({"bar", "baz"});
  logger2.close();

  read = get_file_contents("./error.log");

  std::vector<std::string> lines = split(read, '\n');
  parts = split(lines[1], ':');
  check(parts[3] == " bar baz", "error file is correct for append");

  cleanup();
}

int test_error_log ( ) {
  test_error_log_single();
  test_error_log_multi();
  test_error_log_append();

  done();
}

void test_warn_log_single ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.warn({"foo"});
  logger.close();

  std::string read = get_file_contents("./warn.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo\n", "warn file is correct for a single argument");

  cleanup();
}

void test_warn_log_multi ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.warn({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./warn.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo bar\n", "warn file is correct for multiple arguments");

  cleanup();
}

void test_warn_log_append ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.warn({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./warn.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo bar\n", "warn file is correct for append first read");

  Logger logger2(config);
  logger2.warn({"bar", "baz"});
  logger2.close();

  read = get_file_contents("./warn.log");

  std::vector<std::string> lines = split(read, '\n');
  parts = split(lines[1], ':');
  check(parts[3] == " bar baz", "warn file is correct for append");

  cleanup();
}

int test_warn_log ( ) {
  test_warn_log_single();
  test_warn_log_multi();
  test_warn_log_append();

  done();
}

void test_debug_log_single ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.debug({"foo"});
  logger.close();

  std::string read = get_file_contents("./debug.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo\n", "debug file is correct for a single argument");

  cleanup();
}

void test_debug_log_multi ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.debug({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./debug.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo bar\n", "debug file is correct for multiple arguments");

  cleanup();
}

void test_debug_log_append ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.debug({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./debug.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo bar\n", "debug file is correct for append first read");

  Logger logger2(config);
  logger2.debug({"bar", "baz"});
  logger2.close();

  read = get_file_contents("./debug.log");

  std::vector<std::string> lines = split(read, '\n');
  parts = split(lines[1], ':');
  check(parts[3] == " bar baz", "debug file is correct for append");

  cleanup();
}

int test_debug_log ( ) {
  test_debug_log_single();
  test_debug_log_multi();
  test_debug_log_append();

  done();
}

void test_notice_log_single ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.notice({"foo"});
  logger.close();

  std::string read = get_file_contents("./notice.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[1] == "foo\n", "notice file is correct for a single argument");

  cleanup();
}

void test_notice_log_multi ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.notice({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./notice.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo bar\n", "notice file is correct for multiple arguments");

  cleanup();
}

void test_notice_log_append ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.notice({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./notice.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[3] == " foo bar\n", "notice file is correct for append first read");

  Logger logger2(config);
  logger2.notice({"bar", "baz"});
  logger2.close();

  read = get_file_contents("./notice.log");

  std::vector<std::string> lines = split(read, '\n');
  parts = split(lines[1], ':');
  check(parts[3] == " bar baz", "notice file is correct for append");

  cleanup();
}

int test_notice_log ( ) {
  test_notice_log_single();
  test_notice_log_multi();
  test_notice_log_append();

  done();
}

void test_log_log_single ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.log({"foo"});
  logger.close();

  std::string read = get_file_contents("./cdb.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[1] == " foo\n", "log file is correct for a single argument");

  cleanup();
}

void test_log_log_multi ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.log({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./cdb.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[1] == " foo bar\n", "log file is correct for multiple arguments");

  cleanup();
}

void test_log_log_append ( ) {
  Config config;
  config.logPath = "./";

  Logger logger(config);
  logger.log({"foo", "bar"});
  logger.close();

  std::string read = get_file_contents("./cdb.log");
  std::vector<std::string> parts = split(read, ':');

  check(parts[1] == " foo bar\n", "log file is correct for append first read");

  Logger logger2(config);
  logger2.log({"bar", "baz"});
  logger2.close();

  read = get_file_contents("./cdb.log");

  std::vector<std::string> lines = split(read, '\n');
  parts = split(lines[1], ':');
  check(parts[1] == " bar baz", "log file is correct for append");

  cleanup();
}

int test_log_log ( ) {
  test_log_log_single();
  test_log_log_multi();
  test_log_log_append();

  done();
}
