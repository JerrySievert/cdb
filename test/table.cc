#include "test.h"
#include "table.h"
#include "field.h"

int test_table ( ) {
  Field field1("foo", CDB_STRING);
  Field field2("bar", CDB_INT16);
  Field field3("baz", CDB_INT32);

  Table table("table_name", { field1, field2, field3 });

  check(table.name == "table_name", "the name is correct");
  check(table.fields.size() == 3, "the number of fields is correct");

  std::string serialized = table.serialize();

  check(serialized == "table_name\nfoo:1\nbar:3\nbaz:4\n", "the table is serialized correctly");

  Table table2;

  table2.deserialize(serialized);

  check(table2.name == "table_name", "the table name deserializes");
  check(table2.fields.size(), "there are 3 fields");
  check(table2.fields[0].name == "foo", "the first field is correct");
  check(table2.fields[1].name == "bar", "the second field is correct");
  check(table2.fields[2].name == "baz", "the third field is correct");

  done();
}
