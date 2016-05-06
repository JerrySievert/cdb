#include "../test.h"
#include "store/directory.h"
#include "store/tablestore.h"
#include "table.h"
#include "field.h"
#include "util.h"
#include "config.h"

void test_create_tablestore ( ) {
  make_directory("test/fixtures/store");

  Config config;
  config.dbPath = "test/fixtures";

  string serialized = read_file("test/fixtures/table1");

  Table table;
  table.deserialize(serialized);

  TableStore store(config, table);
  store.create();

  check(directory_exists("test/fixtures/store/table1"), "the directory is created");

  vector<string> contents = read_directory("test/fixtures/store/table1");

  check(contents.size() == 5, "the correct number of entries is read");
  check(contents[0] == ".", ". is found");
  check(contents[1] == "..", ".. is found");
  check(contents[2] == "bar", "field 1 is found");
  check(contents[3] == "baz", "field 2 is found");
  check(contents[4] == "foo", "field 3 is found");

  store.close();

  remove_directory("test/fixtures/table1");
}

int test_tablestore ( ) {
  test_create_tablestore();

  done();
}
