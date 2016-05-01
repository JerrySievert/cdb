#pragma once

#include <string>
#include <vector>

#include "field.h"
#include "config.h"

class Table {
public:
  std::vector<Field> fields;
  std::string name;
  Table ( );
  Table (std::string, std::vector<Field>);
  std::string serialize ();
  void deserialize (std::string);
};
