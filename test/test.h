#pragma once

#include <stdint.h>

extern uint8_t spec;
extern uint16_t test_passed;
extern uint16_t test_failed;

void _test_fail (const char *, const char *, uint16_t);
void _test_pass (const char *);
void _test_start (const char *);

/* Successfull end of the test case */
#define done() return 0

/* Check single condition */
#define check(cond,message) do { if (!(cond)) { _test_fail(message, __FILE__, __LINE__); test_failed++; } else { _test_pass(message); test_passed++; } } while (0)

/* Test runner */
#define test(func, name) do { _test_start(name); func(); } while(0)

int test_error_log ( );
int test_warn_log ( );
int test_debug_log ( );
int test_notice_log ( );
int test_log_log ( );

int test_field ( );
int test_table ( );

int test_directory ( );

int test_tablestore ( );

int test_datum ( );
