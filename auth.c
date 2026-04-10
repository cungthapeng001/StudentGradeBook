#include <stdio.h>
#include <string.h>
#include "auth.h"

bool login() {
    char inputPass[20];
    int attempts = 3;

    while (attempts > 0) {
        printf("\n========= SYSTEM LOGIN =========");
        printf("\nEnter Password: ");
        scanf("%19s", inputPass); 

        if (strcmp(inputPass, APP_PASSWORD) == 0) {
            printf("\nAccess Granted! Welcome to the system.\n");
            return true;
        } else {
            attempts--;
            printf("Access Denied! Incorrect password.");
            printf("\nAttempts remaining: %d\n", attempts);
        }
    }

    printf("\nToo many failed attempts. Program exiting...\n");
    return false;
}