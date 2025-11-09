/**
 * File: signal_alarm.c
 * Modified by: Megan Cranston
 * 
 * Brief summary of program:schedules an alarm to be sent to after 5 seconds
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void handle_alarm(int sig) {
    printf("Received SIGALRM! The alarm went off after 5 seconds.\n");
}

int main() {
    // Register the signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);

    alarm(5);

    printf("Alarm set for 5 seconds.\n");
    pause();  // Wait for any signal

    printf("Exiting program.\n");
    return 0;
}