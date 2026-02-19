#ifndef STUDENT_H
#define STUDENT_H

#define MAX 20 // ကျောင်းသား အယောက် ၂၀ အထိ လက်ခံနိုင်အောင် သတ်မှတ်ထားခြင်း

// Function prototypes - လုပ်ငန်းဆောင်တာများ၏ ပုံစံငယ်များ
char calculateGrade(float p);
void showMenu();
void printResultTable(int students, int subjects, int roll[], char studentName[MAX][50], char subjectName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]);
void addStudentData(int *students, int subjects, int roll[], char studentName[MAX][50], char subjectName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]);

// ဖိုင်သိမ်းဆည်းခြင်းနှင့် ပြန်လည်ဖတ်ရှုခြင်း လုပ်ငန်းဆောင်တာများ
void saveData(int students, int subjects, int roll[], char studentName[MAX][50], char subjectName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]);
void loadData(int *students, int *subjects, int roll[], char studentName[MAX][50], char subjectName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]);

// Log ဖိုင်တွင် မှတ်တမ်းတင်ရန်
void writeLog(const char *message);

#endif