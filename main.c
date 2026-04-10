#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "showAllStudentResult.h"
#include "delete.h"
#include "insert.h"
#include "searchByName.h"
#include "searchByRoll.h"
#include "classTopper.h"

void showMenu() {
    printf("\n====================================\n");
    printf(" \t\t\tSTUDENT RESULT SYSTEM\n");
    printf("====================================\n");
    printf("1. Add New Student Data\n");
    printf("2. Search Result by Name\n");
    printf("3. Search Result by Roll Number\n");
    printf("4. Show Class Topper\n");
    printf("5. Show All Student Results\n");
    printf("6. Delete Student Record\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {


    int students = 0, subjects;
    Student studentList[MAX];
    char subjectName[MAX][50];
    int choice;

    if (!login()){
        return 0;
    }

    loadData(&students, &subjects, studentList, subjectName);

    printf("            Welcome! Student Grade Calculation:\n");

    setupSubjects(&subjects, subjectName);

    do {
        showMenu();
        if (scanf("%d", &choice) != 1) break; 
        getchar();

        switch(choice) {
            case 1:
                addStudentData(&students, subjects, studentList, subjectName);
                break;
            case 2:
                searchByName(students, studentList);
                break;
            case 3:
                searchByRoll(students, studentList);
                break;
            case 4: 
                showClassTopper(students, studentList);
                break;
            case 5:
                printResultTable(students, subjects, studentList, subjectName);
                break;
            case 6:
                deleteStudentData(&students, studentList);
                break;
            case 7:
               saveData(students, subjects, studentList, subjectName);
               printf("Exiting system...\n");
               writeLog("Exited System");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}