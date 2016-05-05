#pragma once

#include <vector>
#include <string>

using namespace std;

vector<string> read_directory (string);
bool make_directory (string);
int remove_directory (string);
bool directory_exists (string);
