#include <nanvix/pm.h>
#include <nanvix/syscall.h>
#include <sys/process.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc != 2)
        exit(EXIT_FAILURE);
    
    pid_t pid = atoi(argv[1]);

     if (pid > 0)
        exit(EXIT_FAILURE);

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
