#include <nanvix/const.h>
#include <nanvix/dev.h>
#include <nanvix/fs.h>
#include <nanvix/klib.h>
#include <nanvix/mm.h>
#include <nanvix/pm.h>
#include <signal.h>

/**
 * @brief Call the process info kernel function
 *
 * @param pid Process id
 * @param process_buf Process buffer
 */
PUBLIC int sys_get_process_info(pid_t pid, struct process_buf *buf){
    if(pid){
        return -1;
    }
    if(buf->pid != pid){
        return -1;
    }
    return do_get_process_info(pid, buf);
}