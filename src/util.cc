#include <regex>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <streambuf>
#include <cerrno>

#include "util.h"

vector<string> split(const string& s, const char c) {
  string buf {""};
  vector<string> v;

  for (auto n:s) {
    if (n != c) {
      buf += n;
    } else {
      if (n == c && buf != "") {
        v.push_back(buf);
        buf = "";
      }
    }
  }

  if (buf != "") {
    v.push_back(buf);
  }

  return v;
}

string read_file (string filename) {
  ifstream file(filename);
  string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

  return str;
  throw errno;
}
