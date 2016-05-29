#pragma once

#include <string>
#include <vector>
#include <stdint.h>

#include "field.h"
#include "config.h"

using namespace std;

class Table {
public:
  vector<Field> fields;
  string name;
  Table ( );
  Table (string, vector<Field>);
  string serialize ();
  void deserialize (string);
  int16_t field (string);
};
