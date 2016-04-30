#include <vector>
#include <iostream>

#include "field.h"
#include "util.h"

Field::Field ( ) {

}

Field::Field (std::string name, FieldType type) {
  this->name = name;
  this->type = type;
}

std::string Field::serialize ( ) {
  return this->name + ":" + std::to_string(this->type) + "\n";
}

void Field::deserialize (std::string serialized) {
  std::vector<std::string> parts = split(serialized, ":");

  this->name = parts[0];
  this->type = std::stoi(parts[1]);
}
