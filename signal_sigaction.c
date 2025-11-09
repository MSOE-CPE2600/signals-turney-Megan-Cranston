/**
 * File: signal_sigaction.c
 * Modified by: Megan Cranston
 * 
 * Brief summary of program:
 *   1. Run the program: ./output
 *   2. The program will display its PID
 *   3. In another terminal, send SIGUSR1 using kill -SIGUSR1 <PID>
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
void sigusr1_handler(int sig, siginfo_t *info, void *context) {
    printf("SIGUSR1 sent by user ID: %d\n", info->si_uid);
}
 
int main() {
    struct sigaction sa;
   
    printf("Program PID: %d\n", getpid());
    printf("Setting up signal handler for SIGUSR1...\n");
   
    sa.sa_sigaction = sigusr1_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
   
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
   
    printf("Signal handler registered successfully.\n");
    printf("Waiting for SIGUSR1 signal...\n");
    printf("Send signal using: kill -SIGUSR1 %d\n\n", getpid());
   
    while (1) {
        pause();
    }
   
    return 0;
}
