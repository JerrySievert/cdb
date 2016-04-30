#include "table.h"

Table::Table (Field *fields, uint8_t size) {
  this->fields = fields;
  this->size = size;
}

std::string Table::serialize ( ) {
  std::string serialized;

  for (uint8_t i = 0; i < this->size; i++) {
    serialized += this->fields[i].serialize();
  }

  return "";
}
