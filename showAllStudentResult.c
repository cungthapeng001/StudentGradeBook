#include <stdio.h>
#include <string.h>
#include <time.h>
#include "showAllStudentResult.h"

char calculateGrade(float p) {
    if (p >= 80) return 'A';
    else if (p >= 65) return 'B';
    else if (p >= 50) return 'C';
    else if (p >= 40) return 'D';
    else return 'F';
}

void printResultTable(int students, int subjects, Student studentList[], char subjectName[MAX][50]) {
    if (students == 0) {
        printf("\nNo data available to show!\n");
        return;
    }

    printf("\n--- FINAL RESULT TABLE ---\n");
    printf("Roll\tName\t\t");
    for (int j = 0; j < subjects; j++) {
        char tempSub[50];
        strcpy(tempSub, subjectName[j]);
        tempSub[strcspn(tempSub, "\n")] = 0;
        printf("%s\t", tempSub);
    }
    printf("Total\tPercent\tGrade\tStatus\n");

    for (int i = 0; i < students; i++) {
        printf("%d\t%s\t\t", studentList[i].roll, studentList[i].name);
        for (int j = 0; j < subjects; j++) {
            printf("%d\t", studentList[i].marks[j]);
        }
        printf("%d\t%.2f\t%c\t%s\n", studentList[i].total, studentList[i].percentage, studentList[i].grade, studentList[i].status);
    }
    writeLog("Viewed Result Table");
}

