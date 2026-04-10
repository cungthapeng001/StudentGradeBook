#include <stdio.h>
#include <string.h>
#include "delete.h"

void deleteStudentData(int *students, Student studentList[]) {
    if (*students == 0) {
        printf("\nNo student data available to delete!\n");
        return;
    }

    int searchRoll, foundIndex = -1;
    printf("\nEnter roll number to delete: ");
    scanf("%d", &searchRoll);
    getchar();

    for (int i = 0; i < *students; i++) {
        if (studentList[i].roll == searchRoll) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        char deletedName[50];
        strcpy(deletedName, studentList[foundIndex].name);

        for (int i = foundIndex; i < *students - 1; i++) {
            studentList[i] = studentList[i + 1];
        }
        (*students)--;
        printf("\nStudent %s (Roll: %d) has been deleted.\n", deletedName, searchRoll);

        char logMsg[100];
        sprintf(logMsg, "Deleted Student: %s (Roll: %d)", deletedName, searchRoll);
        writeLog(logMsg);
    } else {
        printf("\nRoll number %d not found!\n", searchRoll);
    }
}
