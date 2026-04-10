#ifndef STUDENT_H
#define STUDENT_H

#define MAX 20

typedef struct {
    int roll;
    char name[50];
    int marks[MAX];
    int total;
    float percentage;
    char grade;
    char status[5];
} Student;

char calculateGrade(float p);
void printResultTable(int students, int subjects, Student studentList[], char subjectName[MAX][50]);

#include "fileHandler.h"

#endif