#pragma once

//! Directory Utilities
/*!
  Directory utilities for dealing with directories in C++
*/

#include <vector>
#include <string>

using namespace std;

//! reads a directory and returns a vector<string> of its contents
/*!
  \param s - `string` of directory to read
  \returns `vector<string>` - vector of entries, including `.` and `..`
*/
vector<string> read_directory (string);

//! makes a directory, recursively
/*!
  \param s - `string` of directory to create
  \returns `bool` - `true` if created, `false` if not
*/
bool make_directory (string);

//! removes a directory, recursively
/*!
  \param s - `string` of directory to remove
  \returns `int` - 0 on completion, `errno` on error
*/
int remove_directory (string);

//! checks to see if a directory exists
/*!
  \param s - `string` of directory to check
  \returns `bool` - true if directory exists
*/
bool directory_exists (string);
