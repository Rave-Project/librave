#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct task_simply_struct {
    pid_t pid;
    char comm[16];
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