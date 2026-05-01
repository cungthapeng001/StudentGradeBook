#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

typedef struct {
    char userId[50];
    char password[50];
} User;

void registerUser();
bool login();

#endif