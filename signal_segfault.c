/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Megan Cranston
 * 
 * Brief summary of modifications: 
 *      - added a handler for the sigsegv
 *      - called the handler using the signal function
 */


#include <stdio.h>
#include <signal.h>

void handle_sigsegv(int sig) {
    printf("Caught signal %d: Segmentation fault received.\n", sig);
}
 
int main (int argc, char* argv[]) {
 
    signal(SIGSEGV, handle_sigsegv);
   
    // Declare a null pointer
    int* i = NULL;
 
    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);
 
    // Return to exit the program
    return 0;
}