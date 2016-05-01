#include <regex>
#include <string>
#include <sstream>
#include <vector>

#include "util.h"
/*
vector<string> split(const string& input, const string& regex) {
  // passing -1 as the submatch index parameter performs splitting
  regex re(regex);
  sregex_token_iterator
    first{input.begin(), input.end(), re, -1},
    last;
  return {first, last};
}
*/
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
