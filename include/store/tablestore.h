#pragma once

#include "config.h"
#include "table.h"

#include "leveldb/db.h"

class TableStore {
private:
  Config config;
  Table table;
  vector<leveldb::DB *> stores;
public:
  TableStore (Config, Table);
  bool create ( );
  bool open ( );
  void close ( );

};
