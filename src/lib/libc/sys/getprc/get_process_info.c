 /*
 * Copyright(C) 2011-2016 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 *
 * This file is part of Nanvix.
 *
 * Nanvix is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Nanvix is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Nanvix. If not, see <http://www.gnu.org/licenses/>.
 */

#include <nanvix/syscall.h>
#include <nanvix/pm.h>
#include <sys/process.h>
#include <errno.h>
#include <stdio.h>

/*
*
* @brief Collect info about some process
*
* @param pid Process ID
* @param buf Buffer to store process info
*
**/
int get_process_info(pid_t pid, struct process_buf* buf)
{
    int status = 0;

    __asm__ volatile (
        "int $0x80"
        : "=a" (status)
        : "0" (NR_get_process_info),
          "b" (pid),
          "c" (buf)
    );

    /* Error. */
    if (status < 0)
    {
        errno = -status;
        return (-1);
    }

    return (status);
}
