#include <stdio.h>
#include "classTopper.h"

void showClassTopper(int students, Student studentList[]) {
    if (students == 0) {
        printf("No student data available!\n");
    } else {
        int top = 0;
        for (int i = 1; i < students; i++) {
            if (studentList[i].percentage > studentList[top].percentage) top = i;
        }
        printf("\n--- CLASS TOPPER ---\nName: %s\nPercentage: %.2f\nGrade: %c\n", studentList[top].name, studentList[top].percentage, studentList[top].grade);
    }
    // ကြည့်ရှုမှုမှတ်တမ်းကို Log တွင် သိမ်းဆည်းခြင်း
    writeLog("Viewed Class Topper");
}
