#include <iostream>
#include <string>

#include "test.h"

using namespace std;

uint8_t spec = 0;
uint16_t test_passed = 0;
uint16_t test_failed = 0;

void _test_pass (const char *message) {
  if (spec) {
    cout << "  ✓ " << message << endl;
  } else {
    cout << ".";
  }
}

void _test_fail (const char *message, const char *file, uint16_t line) {
  if (spec) {
    cout << "  𝙭 " << message << " (" << file << ":" << line << ")\n";
  } else {
    cout << "𝙭";
  }
}

void _test_start (const char *name) {
  if (spec) {
    cout << endl << name << endl;
  }
}

int main (int argc, char **argv) {
  if (argc > 1) {
    if ((string(argv[1]) == "--spec") || (string(argv[1]) == "-s")) {
      spec = 1;
    }
  }

  test(test_error_log, "test error log");
  test(test_warn_log, "test warn log");
  test(test_debug_log, "test debug log");
  test(test_notice_log, "test notice log");
  test(test_log_log, "test log log");

  test(test_field, "test field");

  test(test_table, "test table");

  test(test_directory, "test directory");

  test(test_tablestore, "test tablestore");

  test(test_datum, "test datum");

  cout << "\nPASSED: " << test_passed << "\nFAILED: " << test_failed << endl;

  return (test_failed > 0 ? 1 : 0);
}
