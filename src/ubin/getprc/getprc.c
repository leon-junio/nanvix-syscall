#include <nanvix/pm.h>
#include <nanvix/syscall.h>
#include <sys/process.h>
#include <stdio.h>


int main(void)
{
    pid_t pid = 1;
    struct process_buf buf; 


    int status = get_process_info(pid, &buf);

    if (status == 0)
    {
        printf("Process ID: %d\n", buf.pid);
        printf("Status: %d\n", buf.status);
        printf("Priority: %d\n", buf.priority);
        printf("User Time: %d\n", buf.utime);
        printf("Kernel Time: %d\n", buf.ktime);
    }
    else
    {
        printf("Error: Process with PID %d not found.\n", pid);
    }

    return 0;
}
