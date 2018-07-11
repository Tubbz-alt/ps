
#ifndef R_PS_INTERNAL_H
#define R_PS_INTERNAL_H

#include "config.h"
#include "ps.h"

#ifdef PS__MACOS

#include <signal.h>

typedef struct {
  pid_t pid;
  double create_time;
  int gone;
} ps_handle_t;

#endif

#ifdef PS__LINUX

#include <signal.h>

typedef struct {
  pid_t pid;
  double create_time;
  int gone;
} ps_handle_t;

#endif

#ifdef PS__WINDOWS

#include <windows.h>

typedef struct {
  DWORD  pid;
  double create_time;
  int gone;
  FILETIME wtime;
} ps_handle_t;

#endif

/* Internal utilities */

SEXP psll__is_running(ps_handle_t *handle);

SEXP ps__get_pw_uid(SEXP r_uid);
SEXP ps__define_signals();
SEXP ps__define_errno();

/* Errors */

extern SEXP ps__last_error;

void PROTECT_PTR(void *ptr);

void *ps__set_error(const char *msg, ...);
void *ps__set_error_from_errno();
SEXP ps__throw_error();

void *ps__access_denied(const char *msg);
void *ps__no_such_process(long pid, const char *name);
void *ps__zombie_process(long pid);
void *ps__no_memory(const char *msg);
void *ps__not_implemented(const char *what);

void *ps__set_error_from_windows_error(long err);

/* Build SEXP values */

SEXP ps__build_string(const char *str, ...);
SEXP ps__build_list(const char *template, ...);
SEXP ps__build_named_list(const  char *template, ...);

/* String conversions */

SEXP ps__str_to_utf8(const char *str);
SEXP ps__str_to_utf8_size(const char *str, size_t size);

#ifdef PS__WINDOWS
SEXP ps__utf16_to_rawsxp(const WCHAR* ws, int size);
SEXP ps__utf16_to_charsxp(const WCHAR* ws, int size);
SEXP ps__utf16_to_strsxp(const WCHAR* ws, int size);
int ps__utf8_to_utf16(const char* s, WCHAR** ws_ptr);
#endif

#endif
