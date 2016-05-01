#pragma once

#include <string>
#include <vector>

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
};
