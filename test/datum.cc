#include "test.h"
#include "field.h"
#include "datum.h"

void test_datum_serialize_string ( ) {
  Datum datum;
  Container container = Container();

  container.t_string = "test";

  datum = Datum(container, CDB_STRING);

  check(datum.container.t_string == "test", "the value is correct");
  check(datum.type == CDB_STRING, "the type is correct");

  string serialized = datum.serialize();

  check(serialized == "1:test\n", "the field is serialized correctly");

  Datum datum2;
  datum2.deserialize(serialized);

  check(datum2.type == CDB_STRING, "the unserialized type is correct");
  check(datum2.container.t_string == "test", "the unserialized value is correct");
}

void test_datum_serialize_int8 ( ) {
  Datum datum;
  Container container = Container();

  container.t_8 = 32;

  datum = Datum(container, CDB_INT8);

  check(datum.container.t_8 == 32, "the value is correct");
  check(datum.type == CDB_INT8, "the type is correct");

  string serialized = datum.serialize();

  check(serialized == "2:32\n", "the field is serialized correctly");

  Datum datum2;
  datum2.deserialize(serialized);

  check(datum2.type == CDB_INT8, "the unserialized type is correct");
  check(datum2.container.t_8 == 32, "the unserialized value is correct");
}

void test_datum_serialize_int16 ( ) {
  Datum datum;
  Container container = Container();

  container.t_16 = 32;

  datum = Datum(container, CDB_INT16);

  check(datum.container.t_16 == 32, "the value is correct");
  check(datum.type == CDB_INT16, "the type is correct");

  string serialized = datum.serialize();

  check(serialized == "3:32\n", "the field is serialized correctly");

  Datum datum2;
  datum2.deserialize(serialized);

  check(datum2.type == CDB_INT16, "the unserialized type is correct");
  check(datum2.container.t_16 == 32, "the unserialized value is correct");
}

void test_datum_serialize_int32 ( ) {
  Datum datum;
  Container container = Container();

  container.t_32 = 32;

  datum = Datum(container, CDB_INT32);

  check(datum.container.t_32 == 32, "the value is correct");
  check(datum.type == CDB_INT32, "the type is correct");

  string serialized = datum.serialize();

  check(serialized == "4:32\n", "the field is serialized and unserialized correctly");

  Datum datum2;
  datum2.deserialize(serialized);

  check(datum2.type == CDB_INT32, "the unserialized type is correct");
  check(datum2.container.t_32 == 32, "the unserialized value is correct");
}

void test_datum_serialize_double ( ) {
  Datum datum;
  Container container = Container();

  container.t_double = 3.14159;

  datum = Datum(container, CDB_DOUBLE);

  check(datum.container.t_double == 3.14159, "the value is correct");
  check(datum.type == CDB_DOUBLE, "the type is correct");

  string serialized = datum.serialize();

  check(serialized.substr(0, 9) == "5:3.14159", "the field is serialized and unserialized correctly");

  Datum datum2;
  datum2.deserialize(serialized);

  check(datum2.type == CDB_DOUBLE, "the unserialized type is correct");
  check(datum2.container.t_double == 3.14159, "the unserialized value is correct");
}

int test_datum ( ) {
  test_datum_serialize_string();
  test_datum_serialize_int8();
  test_datum_serialize_int16();
  test_datum_serialize_int32();
  test_datum_serialize_double();

  done();
}
