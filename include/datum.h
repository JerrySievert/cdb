#pragma once

#include <string>

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
  Datum (Container, FieldType);
  Container container;
  FieldType type;
  string serialize ( );
  void deserialize (string);
};
