#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fileHandler.h"

// ဒေတာများကို .dat ဖိုင်ထဲသို့ သိမ်းဆည်းသည့် function
void saveData(int students, int subjects, Student studentList[], char subjectName[MAX][50]) {
    FILE *fp = fopen("database.dat", "wb");
    if (fp != NULL) {
        fwrite(&students, sizeof(int), 1, fp);
        fwrite(&subjects, sizeof(int), 1, fp);
        fwrite(subjectName, sizeof(char), MAX * 50, fp);
        fwrite(studentList, sizeof(Student), MAX, fp);
        fclose(fp);
        printf("\n[System] Data saved to database.dat\n");
        // လုပ်ဆောင်ချက်ကို Log မှတ်တမ်းတင်ခြင်း
        writeLog("Data saved to database.dat");
    } else {
        printf("\n[Error] Failed to save data!\n");
    }
}

// ဒေတာများကို .dat ဖိုင်မှ ပြန်လည်ဖတ်ရှုသည့် function
void loadData(int *students, int *subjects, Student studentList[], char subjectName[MAX][50]) {
    FILE *fp = fopen("database.dat", "rb");
    if (fp != NULL) {
        fread(students, sizeof(int), 1, fp);
        fread(subjects, sizeof(int), 1, fp);
        fread(subjectName, sizeof(char), MAX * 50, fp);
        fread(studentList, sizeof(Student), MAX, fp);
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
