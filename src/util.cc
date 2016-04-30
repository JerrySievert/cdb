#include <regex>
#include <string>
#include <sstream>
#include <vector>

#include "util.h"
/*
std::vector<std::string> split(const std::string& input, const std::string& regex) {
  // passing -1 as the submatch index parameter performs splitting
  std::regex re(regex);
  std::sregex_token_iterator
    first{input.begin(), input.end(), re, -1},
    last;
  return {first, last};
}
*/
std::vector<std::string> split(const std::string& s, const char c) {
  std::string buf {""};
  std::vector<std::string> v;

  for(auto n:s) {
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
