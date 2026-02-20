#include <stdio.h>
#include <string.h>
#include <time.h>
#include "student.h"

// ရရှိသည့် အမှတ်အပေါ်မူတည်ပြီး Grade ကို တွက်ချက်ပေးသည့် function
char calculateGrade(float p) {
    if (p >= 80) return 'A';
    else if (p >= 65) return 'B';
    else if (p >= 50) return 'C';
    else if (p >= 40) return 'D';
    else return 'F';
}

// အဓိက Menu ကို ပြသပေးသည့် function
void showMenu() {
    printf("\n====================================\n");
    printf("        STUDENT RESULT SYSTEM\n");
    printf("====================================\n");
    printf("1. Add New Student Data\n");
    printf("2. Search Result by Name\n");
    printf("3. Search Result by Roll Number\n");
    printf("4. Show Class Topper\n");
    printf("5. Show All Results\n");
    printf("6. Delete Student Record\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// ကျောင်းသားသစ် ထည့်သွင်းပေးသည့် function
void addStudentData(int *students, int subjects, int roll[], char studentName[MAX][50], char subjectName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]) {
    if (*students >= MAX) {
        printf("\n[Error] Maximum student limit reached!\n");
        return;
    }

    int i = *students;
    total[i] = 0;

    printf("\n--- Adding New Student (Index: %d) ---\n", i + 1);
    printf("Enter roll number: ");
    scanf("%d", &roll[i]);
    getchar(); // buffer clear လုပ်ခြင်း

    printf("Enter student name: ");
    fgets(studentName[i], 50, stdin);
    studentName[i][strcspn(studentName[i], "\n")] = 0; // line အသစ်ကို ဖယ်ထုတ်ခြင်း

    for (int j = 0; j < subjects; j++) {
        char tempSub[50];
        strcpy(tempSub, subjectName[j]);
        tempSub[strcspn(tempSub, "\n")] = 0;

        printf("Enter marks for %s: ", tempSub);
        scanf("%d", &marks[i][j]);
        total[i] += marks[i][j];
    }
    getchar();

    percentage[i] = total[i] / (float)subjects;
    grade[i] = calculateGrade(percentage[i]);
    strcpy(status[i], (percentage[i] >= 40) ? "PASS" : "FAIL");

    (*students)++; // ကျောင်းသားအရေအတွက်ကို တိုးမြှင့်ခြင်း
    printf("\nStudent added successfully!\n");

    // လုပ်ဆောင်ချက်ကို Log မှတ်တမ်းတင်ခြင်း
    char marksStr[256] = "";
    char temp[64];
    for (int j = 0; j < subjects; j++) {
        sprintf(temp, "%s: %d ", subjectName[j], marks[i][j]);
        strcat(marksStr, temp);
    }
    char logMsg[512];
    sprintf(logMsg, "STUDENT ADDED | Roll: %d | Name: %s | Marks: [%s] | Total: %d | Percent: %.2f%% | Grade: %c | Status: %s",
            roll[i], studentName[i], marksStr, total[i], percentage[i], grade[i], status[i]);
    writeLog(logMsg);
}

// ရလဒ်ဇယားကို ပြသပေးသည့် function
void printResultTable(int students, int subjects, int roll[], char studentName[MAX][50], char subjectName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]) {
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
        printf("%d\t%s\t\t", roll[i], studentName[i]);
        for (int j = 0; j < subjects; j++) {
            printf("%d\t", marks[i][j]);
        }
        printf("%d\t%.2f\t%c\t%s\n", total[i], percentage[i], grade[i], status[i]);
    }
    // လုပ်ဆောင်ချက်ကို Log မှတ်တမ်းတင်ခြင်း
    writeLog("Viewed Result Table");
}

// ဒေတာများကို .dat ဖိုင်ထဲသို့ သိမ်းဆည်းသည့် function
void saveData(int students, int subjects, int roll[], char studentName[MAX][50], char subjectName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]) {
    FILE *fp = fopen("database.dat", "wb");
    if (fp != NULL) {
        fwrite(&students, sizeof(int), 1, fp);
        fwrite(&subjects, sizeof(int), 1, fp);
        fwrite(roll, sizeof(int), MAX, fp);
        fwrite(studentName, sizeof(char), MAX * 50, fp);
        fwrite(subjectName, sizeof(char), MAX * 50, fp);
        fwrite(marks, sizeof(int), MAX * MAX, fp);
        fwrite(total, sizeof(int), MAX, fp);
        fwrite(percentage, sizeof(float), MAX, fp);
        fwrite(grade, sizeof(char), MAX, fp);
        fwrite(status, sizeof(char), MAX * 5, fp);
        fclose(fp);
        printf("\n[System] Data saved to database.dat\n");
        // လုပ်ဆောင်ချက်ကို Log မှတ်တမ်းတင်ခြင်း
        writeLog("Data saved to database.dat");
    } else {
        printf("\n[Error] Failed to save data!\n");
    }
}

// ဒေတာများကို .dat ဖိုင်မှ ပြန်လည်ဖတ်ရှုသည့် function
void loadData(int *students, int *subjects, int roll[], char studentName[MAX][50], char subjectName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]) {
    FILE *fp = fopen("database.dat", "rb");
    if (fp != NULL) {
        fread(students, sizeof(int), 1, fp);
        fread(subjects, sizeof(int), 1, fp);
        fread(roll, sizeof(int), MAX, fp);
        fread(studentName, sizeof(char), MAX * 50, fp);
        fread(subjectName, sizeof(char), MAX * 50, fp);
        fread(marks, sizeof(int), MAX * MAX, fp);
        fread(total, sizeof(int), MAX, fp);
        fread(percentage, sizeof(float), MAX, fp);
        fread(grade, sizeof(char), MAX, fp);
        fread(status, sizeof(char), MAX * 5, fp);
        fclose(fp);
        printf("\n[System] Data loaded from database.dat\n");
        // လုပ်ဆောင်ချက်ကို Log မှတ်တမ်းတင်ခြင်း
        writeLog("Data loaded from database.dat");
    }
}

// လုပ်ဆောင်ချက်များကို log.dat ဖိုင်တွင် မှတ်တမ်းတင်ပေးသည့် function
void writeLog(const char *message) {
    FILE *fp = fopen("activity_log.dat", "a");
    if (fp != NULL) {
        time_t now = time(NULL);
        char *timestamp = ctime(&now);
        timestamp[strlen(timestamp) - 1] = '\0'; // shortcut for removing \n
        fprintf(fp, "[%s] %s\n", timestamp, message);
        fclose(fp);
    }
}

