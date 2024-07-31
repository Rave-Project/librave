#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @pid: process id
 * @name: name of process with full path
 * @rss_memory: resident memory size used
 * @vm: virtual memory
 */
struct task_simply_struct {
    pid_t pid;
    char name[255];
    unsigned long int rss_memory;
    unsigned long int vm;
} task_simply_struct;