#pragma once

#include <string>

using namespace std;

typedef uint8_t FieldType;

const FieldType CDB_STRING = 1;
const FieldType CDB_INT8   = 2;
const FieldType CDB_INT16  = 3;
const FieldType CDB_INT32  = 4;
const FieldType CDB_DOUBLE = 5;

class Field {
public:
  Field ( );
  Field (string, FieldType);
  string name;
  FieldType type;
  string serialize ( );
  void deserialize (string);
};
