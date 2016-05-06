#include <vector>

#include "field.h"
#include "util.h"

Field::Field ( ) {

}

Field::Field (string name, FieldType type) {
  this->name = name;
  this->type = type;
}

string Field::serialize ( ) {
  return this->name + ":" + to_string(this->type) + "\n";
}

void Field::deserialize (string serialized) {
  vector<string> parts = split(serialized, ':');

  this->name = parts[0];
  this->type = stoi(parts[1]);
}
