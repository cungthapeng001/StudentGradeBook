#include <stdio.h>
#include <string.h>
#include "delete.h"

// ကျောင်းသားဒေတာကို ပြန်လည်ဖျက်သိမ်းသည့် function
void deleteStudentData(int *students, int subjects, int roll[], char studentName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]) {
    if (*students == 0) {
        printf("\nNo student data available to delete!\n");
        return;
    }

    int searchRoll, foundIndex = -1;
    printf("\nEnter roll number to delete: ");
    scanf("%d", &searchRoll);
    getchar();

    for (int i = 0; i < *students; i++) {
        if (roll[i] == searchRoll) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        char deletedName[50];
        strcpy(deletedName, studentName[foundIndex]);

        // ဒေတာများကို တစ်ခုစီ ရှေ့သို့ တိုးရွှေ့ခြင်း (Shifting)
        for (int i = foundIndex; i < *students - 1; i++) {
            roll[i] = roll[i + 1];
            strcpy(studentName[i], studentName[i + 1]);
            total[i] = total[i + 1];
            percentage[i] = percentage[i + 1];
            grade[i] = grade[i + 1];
            strcpy(status[i], status[i + 1]);
            for (int j = 0; j < subjects; j++) {
                marks[i][j] = marks[i + 1][j];
            }
        }
        (*students)--;
        printf("\nStudent %s (Roll: %d) has been deleted.\n", deletedName, searchRoll);

        // လုပ်ဆောင်ချက်ကို Log မှတ်တမ်းတင်ခြင်း
        char logMsg[100];
        sprintf(logMsg, "Deleted Student: %s (Roll: %d)", deletedName, searchRoll);
        writeLog(logMsg);
    } else {
        printf("\nRoll number %d not found!\n", searchRoll);
    }
}
