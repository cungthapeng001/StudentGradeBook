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
    printf(" \tSTUDENT RESULT SYSTEM\n");
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
    int authChoice;
    bool isAuthenticated = false;

    while (1) {
        isAuthenticated = false; // Reset authentication status for each loop
        
        do {
            printf("\n====================================\n");
            printf(" \tAUTHENTICATION MENU\n");
            printf("====================================\n");
            printf("1. Login\n");
            printf("2. Register\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            
            if (scanf("%d", &authChoice) != 1) {
                getchar(); // clear input
                continue;
            }
            getchar(); // consume newline

            switch(authChoice) {
                case 1:
                    isAuthenticated = login();
                    break;
                case 2:
                    registerUser();
                    break;
                case 3:
                    printf("Exiting program...\n");
                    return 0;
                default:
                    printf("Invalid choice! Try again.\n");
            }
        } while (!isAuthenticated);

        loadData(&students, &subjects, studentList, subjectName);
        printf("\t\t\tWelcome! Student Grade Calculation:\n");
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
                   printf("Logging out... returning to authentication menu.\n");
                   writeLog("User logged out");
                    break;
                default:
                    printf("Invalid choice! Try again.\n");
            }
        } while (choice != 7);
    }
    
    return 0;
}