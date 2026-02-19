#ifndef DELETE_H
#define DELETE_H

#include "student.h"

// ကျောင်းသားဒေတာကို ပြန်လည်ဖျက်သိမ်းသည့် function prototype
void deleteStudentData(int *students, int subjects, int roll[], char studentName[MAX][50], int marks[MAX][MAX], int total[], float percentage[], char grade[], char status[MAX][5]);

#endif
