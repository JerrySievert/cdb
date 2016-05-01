#include "table.h"
#include "util.h"

Table::Table ( ) {

}

Table::Table (std::string name, std::vector<Field> fields) {
  this->name = name;
  this->fields = fields;
}

std::string Table::serialize ( ) {
  std::string serialized;

  serialized = this->name + "\n";

  for (auto field:this->fields) {
    serialized += field.serialize();
  }

  return serialized;
}

void Table::deserialize (std::string serialized) {
  std::vector<std::string> parts = split(serialized, '\n');
  std::vector<Field> fields;

  this->name = parts[0];

  for (int i = 1; i < parts.size(); i++) {
    Field field;
    field.deserialize(parts[i]);
    fields.push_back(field);
  }

  this->fields = fields;
}
