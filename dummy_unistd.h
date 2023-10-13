/**
 * @file        dummy_unistd.h
 * @brief       dummy unistd file for GCC-RX
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

#ifndef DUMMY_UNISTD_H_
#define DUMMY_UNISTD_H_

#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/_types.h>

/* Configuration */
#define FILE_DESCRIPTOR_NUM     (3)
#define PROCESS_ID_NUM          (3)

/* Typedefines */
typedef int     (*close_func_t  )(int fd);
typedef int     (*fstat_func_t  )(int fd, struct stat *buf);
typedef int     (*isatty_func_t )(int fd);
typedef off_t   (*lseek_func_t  )(int fd, off_t offset, int whence);
typedef ssize_t (*read_func_t   )(int fd, void *buf, size_t count);
typedef ssize_t (*write_func_t  )(int fd, const void *buf, size_t count);
typedef struct {
    close_func_t    close_func;
    fstat_func_t    fstat_func;
    isatty_func_t   isatty_func;
    lseek_func_t    lseek_func;
    read_func_t     read_func;
    write_func_t    write_func;
} file_control_functions_t;
typedef int     (*kill_func_t   )(pid_t pid, int sig);

/* Functions */
int register_new_file_descriptor(int fd, const file_control_functions_t *file_control_functions);
int register_new_process(pid_t new_pid, kill_func_t new_kill_func);
void set_new_pid(pid_t pid);

#endif  /* DUMMY_UNISTD_H_ */

/* vim: set ts=4 sw=4 ff=dos ft=c expandtab : */

