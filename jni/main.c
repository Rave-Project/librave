#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct task_simply_struct {
    pid_t pid;
    char comm[200];
};



int someData() {
    return syscall(445);
}