#include <stdio.h>
#include <string.h>
#include "sdm.h"

#define Max_students 100

extern struct student Student[Max_students];
extern struct student students[Max_students];
extern int studentCount;

int viewRecord() {
    FILE *file = fopen("Data.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "STUDENT DETAILS\n");

    // Process the Student array
    for (int i = 0; i < 15; i++) {
        struct student *s1 = &Student[i];

        fprintf(file, "\nName of the student: %s\n", s1->name);
        fprintf(file, "Register Number of the student: %d\n", s1->reg_no);
        fprintf(file, "Age: %d\n", s1->age);
        fprintf(file, "Branch: %s\n", s1->branch);
        fprintf(file, "\n");

        printf("\nName of the student: %s\n", s1->name);
        printf("Register Number of the student: %d\n", s1->reg_no);
        printf("Age: %d\n", s1->age);
        printf("Branch: %s\n", s1->branch);
        printf("_______________________________________\n");
    }

    // Process the students array
    for (int i = 0; i < studentCount; i++) {
        struct student *s1 = &students[i];

        fprintf(file, "\nName of the student: %s\n", s1->name);
        fprintf(file, "Register Number of the student: %d\n", s1->reg_no);
        fprintf(file, "Age: %d\n", s1->age);
        fprintf(file, "Branch: %s\n", s1->branch);
        fprintf(file, "\n");

        printf("\nName of the student: %s\n", s1->name);
        printf("Register Number of the student: %d\n", s1->reg_no);
        printf("Age: %d\n", s1->age);
        printf("Branch: %s\n", s1->branch);
        printf("_______________________________________\n");
    }

    fclose(file);
    return 0;
}
