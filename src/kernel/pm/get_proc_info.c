#include <nanvix/pm.h>
#include <sys/types.h>

/**
 * @brief Call the process info kernel function
 *
 * @param pid Process id
 * @param process_buf Process buffer
 */
PUBLIC int sys_get_process_info(pid_t pid, struct process_buf* buf){
    do_get_process_info(pid, buf);
    return buf->pid == -1 ? -1 : 0;
}
