#include <stdio.h>
#include <string.h>
#include "searchByRoll.h"

void searchByRoll(int students, Student studentList[]) {
    int searchRoll, found = 0;
    printf("Enter roll number to search: ");
    scanf("%d", &searchRoll);
    for (int i = 0; i < students; i++) {
        if (studentList[i].roll == searchRoll) {
            found = 1;
            printf("\n[Found] Name: %s | Total: %d | Percentage: %.2f%% | Grade: %c | Status: %s\n", 
                   studentList[i].name, studentList[i].total, studentList[i].percentage, studentList[i].grade, studentList[i].status);
        }
    }
    if (!found) printf("Roll number not found!\n");

    // ရှာဖွေမှုမှတ်တမ်းကို Log တွင် သိမ်းဆည်းခြင်း
    char logMsg[100];
    sprintf(logMsg, "Searched for Roll Number: %d", searchRoll);
    writeLog(logMsg);
}
