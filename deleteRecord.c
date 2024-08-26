#include <stdio.h>

#define MAX_STUDENTS 100

extern struct student students[MAX_STUDENTS];
extern int studentCount;

void deleteRecord() {
    int reg_no;
    int found = 0;

    printf("Enter the Registration Number you want to delete: ");
    scanf("%d", &reg_no);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].reg_no == reg_no)
        {

            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
            studentCount--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("The record with Registration Number %d has been removed successfully.\n", reg_no);
    } else {
        printf("Record with Registration Number %d not found.\n", reg_no);
    }
}
