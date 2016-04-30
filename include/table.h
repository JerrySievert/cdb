#pragma once

#include <string>

#include "field.h"
#include "config.h"

class Table {
private:
  Field *fields;
  uint8_t size;
  std::string name;
public:
  Table (Field fields[], uint8_t size);
  std::string serialize ();
  bool deserialize (std::string);
};
