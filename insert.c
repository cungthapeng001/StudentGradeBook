#include <stdio.h>
#include <string.h>
#include "insert.h"

// Subject များကို ကနဦးသတ်မှတ်ပေးသည့် function
void setupSubjects(int *subjects, char subjectName[MAX][50]) {
    if (*subjects <= 0 || *subjects > MAX) {
        printf("Enter number of subjects to handle: ");
        scanf("%d", subjects);
        getchar();

        for (int j = 0; j < *subjects; j++) {
            printf("Enter subject %d name: ", j + 1);
            fgets(subjectName[j], 50, stdin);
            subjectName[j][strcspn(subjectName[j], "\n")] = 0;
        }
    } else {
        printf("Loaded %d subjects from previous session.\n", *subjects);
    }
}

void addStudentData(int *students, int subjects, Student studentList[], char subjectName[MAX][50]) {
    if (*students >= MAX) {
        printf("\n[Error] Maximum student limit reached!\n");
        return;
    }

    int i = *students;
    studentList[i].total = 0;

    printf("\n--- Adding New Student (Index: %d) ---\n", i + 1);
    printf("Enter roll number: ");
    scanf("%d", &studentList[i].roll);
    getchar(); // buffer clear လုပ်ခြင်း

    printf("Enter student name: ");
    fgets(studentList[i].name, 50, stdin);
    studentList[i].name[strcspn(studentList[i].name, "\n")] = 0; // line အသစ်ကို ဖယ်ထုတ်ခြင်း

    for (int j = 0; j < subjects; j++) {
        char tempSub[50];
        strcpy(tempSub, subjectName[j]);
        tempSub[strcspn(tempSub, "\n")] = 0;

        printf("Enter marks for %s: ", tempSub);
        scanf("%d", &studentList[i].marks[j]);
        studentList[i].total += studentList[i].marks[j];
    }
    getchar();

    studentList[i].percentage = studentList[i].total / (float)subjects;
    studentList[i].grade = calculateGrade(studentList[i].percentage);
    strcpy(studentList[i].status, (studentList[i].percentage >= 40) ? "PASS" : "FAIL");

    (*students)++; // ကျောင်းသားအရေအတွက်ကို တိုးမြှင့်ခြင်း
    printf("\nStudent added successfully!\n");

    // လုပ်ဆောင်ချက်ကို Log မှတ်တမ်းတင်ခြင်း
    char marksStr[256] = "";
    char temp[64];
    for (int j = 0; j < subjects; j++) {
        sprintf(temp, "%s: %d ", subjectName[j], studentList[i].marks[j]);
        strcat(marksStr, temp);
    }
    char logMsg[512];
    sprintf(logMsg, "STUDENT ADDED | Roll: %d | Name: %s | Marks: [%s] | Total: %d | Percent: %.2f%% | Grade: %c | Status: %s",
            studentList[i].roll, studentList[i].name, marksStr, studentList[i].total, studentList[i].percentage, studentList[i].grade, studentList[i].status);
    writeLog(logMsg);
}
