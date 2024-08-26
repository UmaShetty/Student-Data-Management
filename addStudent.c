#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sdm.h"

#define MAX_STUDENTS 100

struct student students[MAX_STUDENTS];
int studentCount = 0;

int isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(name[i]) && !isspace(name[i]))
        {
            return 0;
        }
    }
    return 1;
}

int isValidBranch(const char *branch)
{
    char lowerBranch[4];
    for (int i = 0; branch[i] != '\0'; i++)
    {
        lowerBranch[i] = tolower(branch[i]);
    }
    lowerBranch[3] = '\0';
    return (strcmp(lowerBranch, "ece") == 0 || strcmp(lowerBranch, "cse") == 0);
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Error: Maximum limit of students reached.\n");
        return;
    }

    struct student newStudent;

    while (1) {
        printf("Enter student name: ");
        scanf(" %[^\n]%*c", newStudent.name);
        if (isValidName(newStudent.name))
        {
            break;
        }
        else
        {
            printf("Invalid name. Name should only consist of alphabets.\n");
        }
    }

    while (1)
    {
        printf("Enter student registration number: ");
        if (scanf("%d", &newStudent.reg_no) == 1 && newStudent.reg_no > 15)
        {
            break;
        }
        else
        {
            printf("The entered registration number is either assigned or invalid.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    while (1)
    {
        printf("Enter student age: ");
        if (scanf("%d", &newStudent.age) == 1 && newStudent.age > 20 && newStudent.age < 35) {
            break;
        } else {
            printf("Invalid age. Age must be greater than 20 and less than 35.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    while (1) {
        printf("Enter student branch (ece/cse): ");
        scanf("%s", newStudent.branch);
        if (isValidBranch(newStudent.branch)) {
            break;
        } else {
            printf("Invalid branch. Branch should be either 'ece' or 'cse'.\n");
        }
    }

    students[studentCount++] = newStudent;

    printf("\nStudent record added successfully.\n");

    FILE *file = fopen("Data.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "\nName of the student: %s\n", newStudent.name);
    fprintf(file, "Register Number of the student: %d\n", newStudent.reg_no);
    fprintf(file, "Age: %d\n", newStudent.age);
    fprintf(file, "Branch: %s\n", newStudent.branch);
    fprintf(file, "\n");

    fclose(file);

    printf("\nSTUDENT ADDED\n");
    printf("___________________\n");
    printf("\nName of the student: %s\n", newStudent.name);
    printf("Register Number of the student: %d\n", newStudent.reg_no);
    printf("Age: %d\n", newStudent.age);
    printf("Branch: %s\n", newStudent.branch);
    printf("___________________\n");
    printf("\n");
}
