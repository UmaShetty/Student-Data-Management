#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sdm.h"

struct student Student[Max_students];
extern struct student students[Max_students];


void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to search for a student using their name
int searchStudent() {
    char sName[50];
    printf("Enter Name of the student: ");
    scanf("%s", sName);

    toLowerCase(sName);

    int found = 0;


    for (int i = 0; i < 15; i++) {
        char lowerName[50];
        strcpy(lowerName, Student[i].name);
        toLowerCase(lowerName);

        if (strcmp(lowerName, sName) == 0) {
            printf("\nName of the student: %s\n", Student[i].name);
            printf("Register Number of the student: %d\n", Student[i].reg_no);
            printf("Age: %d\n", Student[i].age);
            printf("Branch: %s\n", Student[i].branch);
            found = 1;
            break;
        }
    }

    if (!found) {

        for (int i = 0; i < studentCount; i++) {
            char lowerName[50];
            strcpy(lowerName, students[i].name);
            toLowerCase(lowerName);

            if (strcmp(lowerName, sName) == 0) {
                printf("\nName of the student: %s\n", students[i].name);
                printf("Register Number of the student: %d\n", students[i].reg_no);
                printf("Age: %d\n", students[i].age);
                printf("Branch: %s\n", students[i].branch);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Student data not found\n");
    }
    return found;
}

