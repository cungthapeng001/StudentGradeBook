#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "showAllStudentResult.h"

// ဖိုင်သိမ်းဆည်းခြင်းနှင့် ပြန်လည်ဖတ်ရှုခြင်း လုပ်ငန်းဆောင်တာများ
void saveData(int students, int subjects, Student studentList[], char subjectName[MAX][50]);
void loadData(int *students, int *subjects, Student studentList[], char subjectName[MAX][50]);

// Log ဖိုင်တွင် မှတ်တမ်းတင်ရန်
void writeLog(const char *message);

#endif
