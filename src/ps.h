
#ifndef R_PS_H
#define R_PS_H

#define R_USE_C99_IN_CXX 1
#include <Rinternals.h>

/* API to be used from R */

/* ps_handle class */

SEXP psll_handle(SEXP pid, SEXP time);

SEXP psll_pid(SEXP p);
SEXP psll_create_time(SEXP p);

SEXP psll_format(SEXP p);
SEXP psll_parent(SEXP p);
SEXP psll_ppid(SEXP p);
SEXP psll_is_running(SEXP p);
SEXP psll_name(SEXP p);
SEXP psll_exe(SEXP p);
SEXP psll_cmdline(SEXP p);
SEXP psll_status(SEXP p);
SEXP psll_username(SEXP p);
SEXP psll_cwd(SEXP p);
SEXP psll_uids(SEXP p);
SEXP psll_gids(SEXP p);
SEXP psll_terminal(SEXP p);
SEXP psll_environ(SEXP p);
SEXP psll_num_threads(SEXP p);
SEXP psll_cpu_times(SEXP p);
SEXP psll_memory_info(SEXP p);
SEXP psll_send_signal(SEXP p, SEXP sig);
SEXP psll_suspend(SEXP p);
SEXP psll_resume(SEXP p);
SEXP psll_terminate(SEXP p);
SEXP psll_kill(SEXP p);

/* Generic utils used from R */

SEXP ps__init(SEXP psenv, SEXP constenv);
SEXP ps__os_type();

SEXP ps__zombie();
SEXP ps__waitpid(SEXP pid);
SEXP ps__pid_exists2(SEXP r_pid);
SEXP ps__stat_st_rdev(SEXP files);

SEXP ps__pids();
SEXP ps__ppid_map();

#endif
