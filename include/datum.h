#pragma once

#include <string>
#include <stdint.h>

#include "field.h"

using namespace std;

class Container {
public:
  string  t_string;
  int8_t  t_8;
  int16_t t_16;
  int32_t t_32;
  int64_t t_64;
  double  t_double;
};

class Datum {
public:
  Datum ( );
  Datum (string);
  Datum (Container, string, FieldType);
  Container container;
  FieldType type;
  string field;
  string serialize ( );
  void deserialize (string);
  string To_String ( );
  bool is_ok ( );
  int8_t compare (Datum);
private:
  bool ok;
};
