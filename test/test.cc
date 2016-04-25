#include <iostream>
#include <string>

#include "test.h"

uint8_t spec = 0;
uint16_t test_passed = 0;
uint16_t test_failed = 0;

void _test_pass (const char *message) {
  if (spec) {
    std::cout << "  ✓ " << message << std::endl;
  } else {
    std::cout << ".";
  }
}

void _test_fail (const char *message, const char *file, uint16_t line) {
  if (spec) {
    std::cout << "  𝙭 " << message << " (" << file << ":" << line << ")\n";
  } else {
    std::cout << "𝙭";
  }
}

void _test_start (const char *name) {
  if (spec) {
    std::cout << std::endl << name << std::endl;
  }
}

int main (int argc, char **argv) {
  if (argc > 1) {
    if ((strcmp(argv[1], "--spec") == 0) || (strcmp(argv[1], "-s") == 0)) {
      spec = 1;
    }
  }

  test(test_error_log, "test error log");
  test(test_warn_log, "test warn log");
  test(test_warn_log, "test debug log");
  test(test_warn_log, "test notice log");
  test(test_warn_log, "test log log");

  std::cout << "\nPASSED: " << test_passed << "\nFAILED: " << test_failed << std::endl;

  return (test_failed > 0 ? 1 : 0);
}
