#pragma once

#include <stdint.h>

#include "config.h"
#include "table.h"
#include "datum.h"

#include "leveldb/db.h"

//! Table Store Class
/*!
  Contains backing store for reading and writing to and from tables.
 */
class TableStore {
private:
  Config config; //! `Config` object
  Table table; //! `Table` that the `TableStore` represents
  vector<leveldb::DB *> stores;

public:
  /**
    Creates a `TableStore`, with the configuration and tables.
    \param config - `Config` object
    \param table - `Table` object
  */
  TableStore (Config, Table);

  /**
    `bool` - `true` if the `TableStore` is open, `false` if not
  */
  bool is_open;

  /**
    Creates the underlying storage subsystem.
    \returns `bool` - `true` if created, `false` if not
  */
  bool create ( );

  /**
    Opens the underlying storage subsystem.
    \returns `bool` - `true` if created, `false` if not
  */
  bool open ( );

  /**
    Closes the underlying storage subsystem.
  */
  void close ( );

  /**
    Reads a `Datum` from the underlying `TableStore`
    \param `field` - `string` of field name to read from
    \param `rowid` - `uint32_t` rowid to read
    \returns `Datum` - `pointer` if found, `NULL` if not
  */
  Datum *read (string, uint32_t);

  /**
    Writes a `Datum` to the underlying `TableStore`
    \param `field` - `string` of field name to write to
    \param `rowid` - `uint32_t` rowid to write
    \param `Datum` - `Datum` to write
    \returns `bool` - `true` if written, `false` if not
  */
  bool write (string, uint32_t, Datum *);

  /**
    Deletes a `Datum` from the underlying `TableStore`
    \param `field` - `string` of field name to delete from
    \param `rowid` - `uint32_t` rowid to delete
    \returns `bool` - `true` if deleted, `false` if not
  */
  bool del (string, uint32_t);
};
