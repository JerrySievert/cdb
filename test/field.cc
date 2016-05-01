#include "test.h"
#include "field.h"

int test_field ( ) {
  Field field;

  field = Field("foo", CDB_STRING);

  check(field.name == "foo", "the name is correct");
  check(field.type == CDB_STRING, "the type is correct");

  string serialized = field.serialize();

  check(serialized == "foo:1\n", "the field is serialized correctly");

  Field field2;

  field2.deserialize(serialized);

  check(field2.name == "foo", "the deserialized name is correct");
  check(field2.type == CDB_STRING, "the deserialized type is correct");

  done();
}
