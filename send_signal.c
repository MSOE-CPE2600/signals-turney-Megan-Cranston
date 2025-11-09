/**
 * File: send_signal.c
 * Modified by: Megan Cranston
 * 
 * Brief summary of program:
 *      - Takes the PID argument from command line
 *      - Generates a rand int to send 
 *      - calls sigqueue to send the signal with the rand int
 */

 #include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid = atoi(argv[1]);

    srand(time(NULL));
    int value = rand() % 100; 

    // Prepare the signal value
    union sigval sig_data;
    sig_data.sival_int = value;

    printf("Sending SIGUSR1 with value: %d to process %d\n", value, pid);

    // Send the signal with data
    if (sigqueue(pid, SIGUSR1, sig_data) == -1) {
        perror("sigqueue");
        exit(EXIT_FAILURE);
    }

    return 0;
}
