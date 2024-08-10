#include "interrupt_handling.h"
#include <signal.h>
#include <stdio.h>

void interruptHandler(int signal) {
    printf("Interrupt received: %d\n", signal);
}

void initInterrupts() {
    signal(SIGINT, interruptHandler);
}
