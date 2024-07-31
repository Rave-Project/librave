/**
 * This module is used for retrieve all list of process in kernel and user mode.
 * This can be return all info in task_simply_struct. Max size is 2000 process.
 */
#include "process.h"

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
