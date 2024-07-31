/**
 * gpu system managment.
 * 
 * This module is used for syscall on adreno gpu.
 * After Rave Patch (syscall 446) we can use this calls
 * for retrieve gpu information.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gpu_cm.h"

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