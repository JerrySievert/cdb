#include <fstream>
#include <string>
#include "store/tablestore.h"
#include "util.h"
#include "log.h"

using namespace std;

TableStore::TableStore (Config config, Table table) {
  this->config = config;
  this->table = table;

  string definition = read_file(config.dbPath + "/" + table.name);

  table.deserialize(definition);
}

// iterate through all of the fields in the table
// create a leveldb store for each one
bool TableStore::create ( ) {
  for (auto field : table.fields) {
    leveldb::Options options;
    options.create_if_missing = true;
    options.error_if_exists = true;

    leveldb::DB *store;
    string path = config.dbPath + "/store/ + field";
    leveldb::Status status = leveldb::DB::Open(options, path, &store);
  }
}
