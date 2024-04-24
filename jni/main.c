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
};

struct task_simply_struct *task_list(long int *size) {
    struct task_simply_struct *data;
    const long int store_size = 2000;

    data = malloc(store_size * sizeof(struct task_simply_struct));

    if ((*size = syscall(445, data, store_size)) < 0) {
        perror("Syscall error");
        free(data);
        return NULL;
    }

    return data;
}

int gpu_getconf() {
    unsigned int freq[10] = {0};
    int i = 0;
    char buff[20];
    syscall(446, 0, freq, 0);
    int max = 0;

    for (; i < 10; ++i) {
        if (max < freq[i]) {
            max = freq[i];
        }
    }

    return max;
}

unsigned long int adreno_freq(unsigned long freq, unsigned int *table, int flag) {
    return syscall(446, freq, table, flag);
}