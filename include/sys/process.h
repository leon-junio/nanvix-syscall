#ifndef PROCESS_H_
#define PROCESS_H_
#include <nanvix/syscall.h>
#include <nanvix/pm.h>

    extern int get_process_info(pid_t pid, struct process_buf* buf);
#endif