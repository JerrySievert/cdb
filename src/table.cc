#include "table.h"
#include "util.h"

Table::Table ( ) {

}

Table::Table (string name, vector<Field> fields) {
  this->name = name;
  this->fields = fields;
}

string Table::serialize ( ) {
  string serialized;

  serialized = this->name + "\n";

  for (auto field:this->fields) {
    serialized += field.serialize();
  }

  return serialized;
}

void Table::deserialize (string serialized) {
  vector<string> parts = split(serialized, '\n');
  vector<Field> fields;

  this->name = parts[0];

  for (int i = 1; i < parts.size(); i++) {
    Field field;
    field.deserialize(parts[i]);
    fields.push_back(field);
  }

  this->fields = fields;
}
