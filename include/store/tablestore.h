#pragma once

#include <stdint.h>

#include "config.h"
#include "table.h"
#include "datum.h"

#include "leveldb/db.h"

class TableStore {
private:
  Config config;
  Table table;
  vector<leveldb::DB *> stores;
public:
  bool is_open;
  TableStore (Config, Table);
  bool create ( );
  bool open ( );
  void close ( );
  Datum *read (uint32_t);
  bool write (uint32_t, Datum *);
};
