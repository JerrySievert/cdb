#pragma once

#include <vector>
#include <string>

using namespace std;

#include "config.h"
#include "table.h"

class Structure {
private:
  Config config;
public:
  Structure (Config);
  vector<Table> tables ( );
  Table get_table (string);
  vector<string> table_names ( );
}
