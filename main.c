#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "auth.c"
#include "student.h"
#include "student.c"

int main() {
    // စနစ်အတွင်းသို့ ဝင်ရောက်ခြင်း
    if (!login()){
        return 0;
    }

    int students = 0, subjects;
    int marks[MAX][MAX], total[MAX], roll[MAX];
    float percentage[MAX];
    char grade[MAX], status[MAX][5];
    char studentName[MAX][50], subjectName[MAX][50];
    int choice;

    // ယခင်သိမ်းဆည်းထားသော ဒေတာများကို ပြန်လည်ဖတ်ရှုခြင်း
    loadData(&students, &subjects, roll, studentName, subjectName, marks, total, percentage, grade, status);

    printf("Welcome! Student Grade Calculation:\n");
    printf("Enter number of subjects to handle: ");
    scanf("%d", &subjects);
    getchar();

    for (int j = 0; j < subjects; j++) {
        printf("Enter subject %d name: ", j + 1);
        fgets(subjectName[j], 50, stdin);
        subjectName[j][strcspn(subjectName[j], "\n")] = 0;
    }

    do {
        showMenu(); // ပင်မမီနူးကို ပြသခြင်း
        if (scanf("%d", &choice) != 1) break; 
        getchar();

        switch(choice) {
            case 1:
                // ကျောင်းသားသစ် အချက်အလက် ထည့်သွင်းခြင်း
                addStudentData(&students, subjects, roll, studentName, subjectName, marks, total, percentage, grade, status);
                break;
            case 2: {
                // ကျောင်းသားအမည်ဖြင့် ရှာဖွေခြင်း
                char searchName[50];
                int found = 0;
                printf("Enter student name to search: ");
                fgets(searchName, 50, stdin);
                searchName[strcspn(searchName, "\n")] = 0;
                for (int i = 0; i < students; i++) {
                    if (strcmp(studentName[i], searchName) == 0) {
                        found = 1;
                        printf("\n[Found] Roll: %d | Total: %d | %.2f%% | Grade: %c | %s\n", roll[i], total[i], percentage[i], grade[i], status[i]);
                    }
                }
                if (!found) printf("Student not found!\n");

                // ရှာဖွေမှုမှတ်တမ်းကို Log တွင် သိမ်းဆည်းခြင်း
                char logMsg[100];
                sprintf(logMsg, "Searched for Student Name: %s", searchName);
                writeLog(logMsg);
                break;
            }
            case 3: {
                // ခုံနံပါတ်ဖြင့် ရှာဖွေခြင်း
                int searchRoll, found = 0;
                printf("Enter roll number to search: ");
                scanf("%d", &searchRoll);
                for (int i = 0; i < students; i++) {
                    if (roll[i] == searchRoll) {
                        found = 1;
                        printf("\n[Found] Name: %s | Total: %d | Percentage: %.2f%% | Grade: %c | Status: %s\n", studentName[i], total[i], percentage[i], grade[i], status[i]);
                    }
                }
                if (!found) printf("Roll number not found!\n");

                // ရှာဖွေမှုမှတ်တမ်းကို Log တွင် သိမ်းဆည်းခြင်း
                char logMsg[100];
                sprintf(logMsg, "Searched for Roll Number: %d", searchRoll);
                writeLog(logMsg);
                break;
            }
            case 4: 
            {
                // အမှတ်အများဆုံးရသူကို ပြသခြင်း
                if (students == 0) {
                    printf("No student data available!\n");
                } else {
                    int top = 0;
                    for (int i = 1; i < students; i++) {
                        if (percentage[i] > percentage[top]) top = i;
                    }
                    printf("\n--- CLASS TOPPER ---\nName: %s\nPercentage: %.2f\nGrade: %c\n", studentName[top], percentage[top], grade[top]);
                }
                // ကြည့်ရှုမှုမှတ်တမ်းကို Log တွင် သိမ်းဆည်းခြင်း
                writeLog("Viewed Class Topper");
                break;
            }
            case 5:
            {
                // ရလဒ်ဇယားကို ပြသခြင်း
                printResultTable(students, subjects, roll, studentName, subjectName, marks, total, percentage, grade, status);
                break;
            }
            case 6:
            {
               // စနစ်မှ မထွက်မီ ဒေတာများကို သိမ်းဆည်းခြင်း
               saveData(students, subjects, roll, studentName, subjectName, marks, total, percentage, grade, status);
               printf("Exiting system...\n");
               // ထွက်ခွာမှုမှတ်တမ်းကို Log တွင် သိမ်းဆည်းခြင်း
               writeLog("Exited System");
                break;
            }
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}