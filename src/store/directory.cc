#include <dirent.h>
#include <vector>
#include <iostream>
#include <cassert>

#include <sys/stat.h>
#include <ftw.h>

#include "util.h"
#include "store/directory.h"

vector<string> read_directory (string path) {
  DIR *dir;
  struct dirent *ent;
  vector<string> results;

  if ((dir = opendir(path.c_str())) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      results.push_back(string(ent->d_name));
    }

    closedir (dir);
  }

  return results;
}

bool make_directory (string name) {
  bool relative = (name[0] != '/');
  vector<string> paths = split(name, '/');

  string path = relative ? "" : "/";

  for (auto part : paths) {
    path += part + "/";

    int error = mkdir(path.c_str(), S_IRWXU);

    if (error == -1) {
      assert(errno);
    }
  }

  return true;
}

static int unlink_cb (const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
  int error = remove(fpath);

  if (error) {
    perror(fpath);
  }

  return error;
}

int remove_directory (string path) {
  return nftw(path.c_str(), unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
}

bool directory_exists (string path) {
  struct stat buf;
  int error = stat(path.c_str(), &buf);

  if (error == -1) {
    return false;
  }

  if (buf.st_mode == S_IFDIR) {
    return true;
  }

  return false;
}
