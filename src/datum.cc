#include <string>
#include <vector>
#include <stdlib.h>

#include "datum.h"
#include "util.h"

Datum::Datum ( ) {
}

Datum::Datum (Container container, FieldType type) {
  this->container = container;
  this->type = type;
}


string Datum::serialize ( ) {
  string ret;

  ret = to_string(this->type) + ":";
  switch (this->type) {
    case CDB_STRING:
    ret += this->container.t_string;
    break;

    case CDB_INT8:
    ret += to_string(this->container.t_8);
    break;

    case CDB_INT16:
    ret += to_string(this->container.t_16);
    break;

    case CDB_INT32:
    ret += to_string(this->container.t_32);
    break;

    case CDB_DOUBLE:
    ret += to_string(this->container.t_double);
    break;
  }

  ret += '\n';

  return ret;
}

void Datum::deserialize (string serialized) {
  vector<string> parts = split(serialized, ':');

  this->type = stoi(parts[0]);

  switch (this->type) {
    case CDB_STRING:
    this->container.t_string = parts[1].substr(0, parts[1].length() - 1);
    break;

    case CDB_INT8:
    this->container.t_8 = atoi(parts[1].c_str());
    break;

    case CDB_INT16:
    this->container.t_16 = atoi(parts[1].c_str());
    break;

    case CDB_INT32:
    this->container.t_32 = atoi(parts[1].c_str());
    break;

    case CDB_DOUBLE:
    this->container.t_double = atof(parts[1].c_str());
    break;
  }
}
