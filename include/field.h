#pragma once

#include <string>

typedef uint8_t FieldType;

const FieldType CDB_STRING = 1;
const FieldType CDB_INT8   = 2;
const FieldType CDB_INT16  = 3;
const FieldType CDB_INT32  = 4;

class Field {
public:
  Field ( );
  Field (std::string, FieldType);
  std::string name;
  FieldType type;
  std::string serialize ( );
  void deserialize (std::string);
};
