#include <stdio.h>
#include <string.h>
#include "searchByName.h"

void searchByName(int students, Student studentList[]) {
    char searchName[50];
    int found = 0;
    printf("Enter student name to search: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    for (int i = 0; i < students; i++) {
        if (strcmp(studentList[i].name, searchName) == 0) {
            found = 1;
            printf("\n[Found] Roll: %d | Total: %d | %.2f%% | Grade: %c | %s\n", 
                   studentList[i].roll, studentList[i].total, studentList[i].percentage, studentList[i].grade, studentList[i].status);
        }
    }
    if (!found) printf("Student not found!\n");

    // ရှာဖွေမှုမှတ်တမ်းကို Log တွင် သိမ်းဆည်းခြင်း
    char logMsg[100];
    sprintf(logMsg, "Searched for Student Name: %s", searchName);
    writeLog(logMsg);
}
