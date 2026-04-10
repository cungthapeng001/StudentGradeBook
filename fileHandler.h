#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "showAllStudentResult.h"

void saveData(int students, int subjects, Student studentList[], char subjectName[MAX][50]);
void loadData(int *students, int *subjects, Student studentList[], char subjectName[MAX][50]);

void writeLog(const char *message);

#endif
