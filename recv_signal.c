/**
 * File: recv_signal.c
 * Modified by: Megan Cranston
 * 
 * Brief summary of program:
 */

 #include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig, siginfo_t *info, void *context) {
    // Print the integer sent via sigqueue
    printf("Received SIGUSR1 with value: %d\n", info->si_value.sival_int);
}

int main() {
    struct sigaction sa;

    // Zero out the sigaction structure
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;

    // Register handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Receiver PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    while (1) {
        // Sleep until a signal arrives
        pause();  
    }

    return 0;
}
