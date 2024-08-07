#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INIT __attribute__((constructor))

void sigsys_handler(int signum) {
    //printf("Caught SIGSYS: illegal syscall attempted.\n");
    { /* empty statement */ }
}

void initialize_signal_handler() {
    struct sigaction sa;
    sa.sa_handler = sigsys_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGSYS, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
}

INIT void _init() {
    initialize_signal_handler();
}
