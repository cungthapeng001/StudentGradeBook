#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "showAllStudentResult.h"
#include "delete.h"
#include "insert.h"
#include "searchByName.h"
#include "searchByRoll.h"
#include "classTopper.h"

// အဓိက Menu ကို ပြသပေးသည့် function
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

    // စနစ်အတွင်းသို့ ဝင်ရောက်ခြင်း
    if (!login()){
        return 0;
    }

    // ယခင်သိမ်းဆည်းထားသော ဒေတာများကို ပြန်လည်ဖတ်ရှုခြင်း
    loadData(&students, &subjects, studentList, subjectName);

    printf("            Welcome! Student Grade Calculation:\n");

    // အကယ်၍ subjects မရှိသေးမှသာ မေးမြန်းခြင်း
    setupSubjects(&subjects, subjectName);

    do {
        showMenu(); // ပင်မမီနူးကို ပြသခြင်း
        if (scanf("%d", &choice) != 1) break; 
        getchar();

        switch(choice) {
            case 1:
                // ကျောင်းသားသစ် အချက်အလက် ထည့်သွင်းခြင်း
                addStudentData(&students, subjects, studentList, subjectName);
                break;
            case 2:
                // ကျောင်းသားအမည်ဖြင့် ရှာဖွေခြင်း
                searchByName(students, studentList);
                break;
            case 3:
                // ခုံနံပါတ်ဖြင့် ရှာဖွေခြင်း
                searchByRoll(students, studentList);
                break;
            case 4: 
                // အမှတ်အများဆုံးရသူကို ပြသခြင်း
                showClassTopper(students, studentList);
                break;
            case 5:
                // ရလဒ်ဇယားကို ပြသခြင်း
                printResultTable(students, subjects, studentList, subjectName);
                break;
            case 6:
                // ကျောင်းသားဒေတာကို ဖျက်သိမ်းခြင်း
                deleteStudentData(&students, studentList);
                break;
            case 7:
               // စနစ်မှ မထွက်မီ ဒေတာများကို သိမ်းဆည်းခြင်း
               saveData(students, subjects, studentList, subjectName);
               printf("Exiting system...\n");
               // ထွက်ခွာမှုမှတ်တမ်းကို Log တွင် သိမ်းဆည်းခြင်း
               writeLog("Exited System");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}