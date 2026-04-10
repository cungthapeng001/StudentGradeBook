#ifndef STUDENT_H
#define STUDENT_H

#define MAX 20 // ကျောင်းသား အယောက် ၂၀ အထိ လက်ခံနိုင်အောင် သတ်မှတ်ထားခြင်း

// ကျောင်းသားတစ်ဦးချင်းစီ၏ အချက်အလက်များ သိမ်းဆည်းရန် Structure
typedef struct {
    int roll;
    char name[50];
    int marks[MAX];
    int total;
    float percentage;
    char grade;
    char status[5];
} Student;

// Function prototypes - လုပ်ငန်းဆောင်တာများ၏ ပုံစံငယ်များ
char calculateGrade(float p);
void printResultTable(int students, int subjects, Student studentList[], char subjectName[MAX][50]);

#include "fileHandler.h"

#endif