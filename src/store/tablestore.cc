#include <fstream>
#include <string>
#include "store/tablestore.h"
#include "store/directory.h"
#include "datum.h"
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
  make_directory(config.dbPath + "/store/" + table.name);

  for (auto field : table.fields) {
    leveldb::Options options;
    options.create_if_missing = true;
    options.error_if_exists = true;

    leveldb::DB *store;
    string path = config.dbPath + "/store/" + table.name + "/" + field.name;
    leveldb::Status status = leveldb::DB::Open(options, path, &store);

    if (!status.ok()) {
      close();
      return false;
    }

    stores.push_back(store);
  }

  this->is_open = true;

  return true;
}

void TableStore::close ( ) {
  for (auto store : stores) {
    delete store;
  }

  stores.clear();

  this->is_open = false;
}

bool TableStore::write (string field, uint32_t rowid, Datum *datum) {
  string _rowid = to_string(rowid);

  int16_t field_num = this->table.field(field);

  if (field_num == -1) {
    return false;
  }

  leveldb::DB *store = this->stores[field_num];
  leveldb::Status status = store->Put(leveldb::WriteOptions(), to_string(rowid), datum->serialize());

  if (status.ok()) {
    return true;
  }

  return false;
}

Datum *TableStore::read (string field, uint32_t rowid) {
  Datum *datum;
  string results;
  int16_t field_num = this->table.field(field);

  if (field_num == -1) {
    return NULL;
  }

  leveldb::DB *store = this->stores[field_num];
  leveldb::Status status = store->Get(leveldb::ReadOptions(), to_string(rowid), &results);

  if (status.ok() == false) {
    return NULL;
  }

  datum = new Datum(results);

  if (datum->is_ok() == false) {
    delete datum;
    return NULL;
  }

  return datum;
}

bool TableStore::del (string field, uint32_t rowid) {
  int16_t field_num = this->table.field(field);

  if (field_num == -1) {
    return false;
  }

  leveldb::DB *store = this->stores[field_num];
  leveldb::Status status = store->Delete(leveldb::WriteOptions(), to_string(rowid));

  if (status.ok()) {
    return true;
  }

  return false;
}
