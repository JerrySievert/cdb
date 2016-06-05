#pragma once

using namespace std;

//! Configuration Class
/*!
  Contains database configuration for running.
 */

class Config {
public:
  string logPath; /**< Path that all log files should reside in */
  string dbPath;  /**< Path that all database files live in */
};
