#include <algorithm>
#include "../test.h"
#include "store/directory.h"

void test_read_directory ( ) {
  vector<string> contents = read_directory("test/fixtures");

  sort(contents.begin(), contents.end());

  check(contents.size() == 5, "the correct number of entries is read");
  check(contents[0] == ".", ". is found");
  check(contents[1] == "..", ".. is found");
  check(contents[2] == "table1", "table1 is found");
  check(contents[3] == "table2", "table2 is found");
  check(contents[4] == "table3", "table3 is found");
}

void test_make_directory ( ) {
  make_directory("test/fixtures/bar/foo");
  check(directory_exists("test/fixtures/bar/foo") == true, "the directory is created");
}

void test_remove_directory ( ) {
  remove_directory("test/fixtures/bar");
  check(directory_exists("test/fixtures/bar") == false, "the directory is removed");
}

int test_directory ( ) {
  test_read_directory();
  test_make_directory();
  test_remove_directory();

  done();
}
