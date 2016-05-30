#include <iostream>
#include <algorithm>
#include "../test.h"
#include "store/directory.h"
#include "store/tablestore.h"
#include "table.h"
#include "field.h"
#include "util.h"
#include "config.h"

TableStore *setup_store ( ) {
  make_directory("test/fixtures/store");

  Config config;
  config.dbPath = "test/fixtures";

  string serialized = read_file("test/fixtures/table1");

  Table table;
  table.deserialize(serialized);

  static TableStore *store = new TableStore(config, table);
  store->create();

  return store;
}

void test_create_tablestore ( ) {
  TableStore *store = setup_store();

  check(directory_exists("test/fixtures/store/table1"), "the directory is created");

  vector<string> contents = read_directory("test/fixtures/store/table1");

  sort(contents.begin(), contents.end());

  check(contents.size() == 5, "the correct number of entries is read");
  check(contents[0] == ".", ". is found");
  check(contents[1] == "..", ".. is found");
  check(contents[2] == "bar", "field 1 is found");
  check(contents[3] == "baz", "field 2 is found");
  check(contents[4] == "foo", "field 3 is found");

  store->close();

  remove_directory("test/fixtures/store");
}

void test_write_datastore ( ) {
  TableStore *store = setup_store();
  Datum datum("1:foo:hello world\n");

  check(store->write("foo", 123, &datum) == true, "writing to a valid field returns true");

  check(store->write("foobar", 123, &datum) == false, "writing to an invalid field returns false");

  store->close();

  remove_directory("test/fixtures/store");
}

void test_read_datastore ( ) {
  TableStore *store = setup_store();
  Datum datum_w("1:foo:hello world\n");

  store->write("foo", 123, &datum_w);

  Datum *datum;

  check(store->read("foobar", 123) == NULL, "reading from an invalid field returns NULL");
  check(store->read("baz", 123) == NULL, "reading from an empty field returns NULL");
  check(store->read("foo", 134) == NULL, "reading an empty value returns NULL");

  datum = store->read("foo", 123);

  check(datum != NULL, "reading a non-empty value returns a Datum");
  check(datum->is_ok() == true, "the Datum is ok");
  check(datum->type == CDB_STRING, "the type is correct");
  check(datum->container.t_string == "hello world", "the value is correct");

  store->close();

  remove_directory("test/fixtures/store");
}

int test_tablestore ( ) {
  test_create_tablestore();
  test_write_datastore();
  test_read_datastore();

  done();
}
