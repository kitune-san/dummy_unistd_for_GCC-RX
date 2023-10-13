/**
 * @file        dummy_unistd.c
 * @brief       dummy unistd file for GCC-RX
 * @attention   These function are not thread safe, not reentrant.
 * @note
 *
 * BSD 1-Clause License
 *
 * Copyright (c) 2023, kitune-san
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "dummy_unistd.h"

static file_control_functions_t file_control_functions_list[FILE_DESCRIPTOR_NUM] = {NULL};

/**
 * @brief       Register file control functions
 * @param[in]   fd                      : file descriptor
 * @param[in]   file_control_functions  : file control functions
 * @return      0 : Success / -1 : Failure
 */
int register_new_file_descriptor(int fd, const file_control_functions_t *file_control_functions)
{
    unsigned int ufd = (unsigned int)fd;
    if (ufd >= FILE_DESCRIPTOR_NUM) {
        return -1;
    }
    if (file_control_functions == NULL) {
        return -1;
    }
    file_control_functions_list[fd] = *file_control_functions;
    return 0;
}

/**
 * @brief       close()
 * @param[in]   fd      : file descriptor
 * @return      0 : Success / -1 : Failure
 */
int close(int fd)
{
    unsigned int ufd = (unsigned int)fd;
    if (ufd >= FILE_DESCRIPTOR_NUM) {
        return -1;
    }
    if (file_control_functions_list[fd].close_func == NULL) {
        return -1;
    }
    return file_control_functions_list[fd].close_func(fd);
}

/**
 * @brief       fstat()
 * @param[in]   fd      : file descriptor
 * @param[out]  buf     : state buffer
 * @return      0 : Success / -1 : Failure
 */
int fstat(int fd, struct stat *buf)
{
    unsigned int ufd = (unsigned int)fd;
    if (ufd >= FILE_DESCRIPTOR_NUM) {
        return -1;
    }
    if (file_control_functions_list[fd].fstat_func == NULL) {
        return -1;
    }
    return file_control_functions_list[fd].fstat_func(fd, buf);
}

/**
 * @brief       isatty()
 * @param[in]   fd      : file descriptor
 * @return      0 : Success / -1 : Failure
 */
int isatty(int fd)
{
    unsigned int ufd = (unsigned int)fd;
    if (ufd >= FILE_DESCRIPTOR_NUM) {
        return -1;
    }
    if (file_control_functions_list[fd].isatty_func == NULL) {
        return -1;
    }
    return file_control_functions_list[fd].isatty_func(fd);
}

/**
 * @brief       lseek()
 * @param[in]   fd      : file descriptor
 * @param[in]   offset  : offset
 * @param[in]   whence  : SEEK_SET/SEEK_CUR/SEEK_END
 * @return      0 : Success / -1 : Failure
 */
off_t lseek(int fd, off_t offset, int whence)
{
    unsigned int ufd = (unsigned int)fd;
    if (ufd >= FILE_DESCRIPTOR_NUM) {
        return -1;
    }
    if (file_control_functions_list[fd].lseek_func == NULL) {
        return -1;
    }
    return file_control_functions_list[fd].lseek_func(fd, offset, whence);
}

/**
 * @brief       read()
 * @param[in]   fd      : file descriptor
 * @param[out]  buf     : read buffer
 * @param[in]   count   : read count
 * @return      Read count
 */
int read(int fd, void *buf, size_t count)
{
    unsigned int ufd = (unsigned int)fd;
    if (ufd >= FILE_DESCRIPTOR_NUM) {
        return 0;
    }
    if (file_control_functions_list[fd].read_func == NULL) {
        return 0;
    }
    return file_control_functions_list[fd].read_func(fd, buf, count);
}

/**
 * @brief       write()
 * @param[in]   fd      : file descriptor
 * @param[in]   buf     : write buffer
 * @param[in]   count   : write count
 * @return      0 : Success / -1 : Failure
 */
int write(int fd, const void *buf, size_t count)
{
    unsigned int ufd = (unsigned int)fd;
    if (ufd >= FILE_DESCRIPTOR_NUM) {
        return -1;
    }
    if (file_control_functions_list[fd].write_func == NULL) {
        return -1;
    }
    return file_control_functions_list[fd].write_func(fd, buf, count);
}

static pid_t        now_pid     = 1;
static kill_func_t  kill_func_list[PROCESS_ID_NUM] = {NULL};

/**
 * @brief       Register new process id
 * @param[in]   new_pid         : new peocess id
 * @param[in]   new_kill_func   : new kill(send SIGNAL) function
 * @return      0 : Success / -1 : Failure
 */
int register_new_process(pid_t new_pid, kill_func_t new_kill_func)
{
    if (new_pid >= PROCESS_ID_NUM) {
        return -1;
    }
    kill_func_list[new_pid] = new_kill_func;
    return 0;
}

/**
 * @brief       set_new_pid()
 * @param       PID
 * @return      None
 */
void set_new_pid(pid_t pid)
{
    now_pid = pid;
}

/**
 * @brief       getpid()
 * @param       None
 * @return      PID
 */
pid_t getpid(void)
{
    return now_pid;
}

/**
 * @brief       kill()
 * @param[in]   pid : PID
 * @param[in]   sig : SIGNAL
 * @return      0 : Success / -1 : Failure
 */
int kill(pid_t pid, int sig)
{
    unsigned int i = (unsigned int)pid;

    if (pid >= PROCESS_ID_NUM) {
        return -1;
    }
    if (pid <= 0) {
        if (now_pid >= PROCESS_ID_NUM) {
            return -1;
        }
        i = (unsigned int)now_pid;
    }
    if (kill_func_list[i] == NULL) {
        return -1;
    }
    return kill_func_list[i](pid, sig);
}

/* vim: set ts=4 sw=4 ff=dos ft=c expandtab : */

