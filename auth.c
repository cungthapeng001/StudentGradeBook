#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auth.h"

const char* USERS_FILE = "users.dat";

void registerUser() {
    User newUser, existingUser;
    FILE *file;
    bool exists = false;

    printf("\n========= USER REGISTRATION =========\n");
    printf("Enter new User ID (max 49 chars): ");
    scanf("%49s", newUser.userId);

    // Check if user already exists
    file = fopen(USERS_FILE, "rb");
    if (file != NULL) {
        while (fread(&existingUser, sizeof(User), 1, file)) {
            if (strcmp(existingUser.userId, newUser.userId) == 0) {
                exists = true;
                break;
            }
        }
        fclose(file);
    }

    if (exists) {
        printf("Error: User ID '%s' already exists. Please try logging in or choose a different ID.\n", newUser.userId);
        return;
    }

    printf("Enter new Password (max 49 chars): ");
    scanf("%49s", newUser.password);

    file = fopen(USERS_FILE, "ab");
    if (file == NULL) {
        printf("Error opening users file for writing!\n");
        return;
    }

    fwrite(&newUser, sizeof(User), 1, file);
    fclose(file);

    printf("Registration successful! You can now log in.\n");
}

bool login() {
    User inputUser, existingUser;
    int attempts = 3;
    FILE *file;
    bool found = false;

    while (attempts > 0) {
        printf("\n========= SYSTEM LOGIN =========\n");
        printf("Enter User ID: ");
        scanf("%49s", inputUser.userId);
        printf("Enter Password: ");
        scanf("%49s", inputUser.password);

        file = fopen(USERS_FILE, "rb");
        if (file == NULL) {
            printf("No registered users found. Please register first.\n");
            return false;
        }

        found = false;
        while (fread(&existingUser, sizeof(User), 1, file)) {
            if (strcmp(existingUser.userId, inputUser.userId) == 0 &&
                strcmp(existingUser.password, inputUser.password) == 0) {
                found = true;
                break;
            }
        }
        fclose(file);

        if (found) {
            printf("\nAccess Granted! Welcome to the system, %s.\n", existingUser.userId);
            return true;
        } else {
            attempts--;
            printf("Access Denied! Incorrect User ID or password.\n");
            printf("Attempts remaining: %d\n", attempts);
        }
    }

    printf("\nToo many failed attempts. Returning to menu...\n");
    return false;
}