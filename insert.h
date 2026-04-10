#ifndef INSERT_H
#define INSERT_H

#include "showAllStudentResult.h"

void setupSubjects(int *subjects, char subjectName[MAX][50]);
void addStudentData(int *students, int subjects, Student studentList[], char subjectName[MAX][50]);

#endif
