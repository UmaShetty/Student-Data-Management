#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sdm.h"

struct student Student[Max_students];
extern struct student students[Max_students];

// Helper function to convert a string to lowercase
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

    // Convert the input name to lowercase
    toLowerCase(sName);

    FILE *file = fopen("Data.txt", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 0;
    }

    int found = 0;

    // Search in the Student array
    for (int i = 0; i < 15; i++) {
        fscanf(file, "\nName of the student: %49[^\n]\n", Student[i].name);
        fscanf(file, "Register Number of the student: %d\n", &Student[i].reg_no);
        fscanf(file, "Age: %d\n", &Student[i].age);
        fscanf(file, "Branch: %s\n", Student[i].branch);

        // Convert the name to lowercase for comparison
        char lowerName[50];
        strcpy(lowerName, Student[i].name);
        toLowerCase(lowerName);

        // Compares entered name with existing data
        if (strcmp(lowerName, sName) == 0) {
            printf("\nName of the student: %s\n", Student[i].name);
            printf("Register Number of the student: %d\n", Student[i].reg_no);
            printf("Age: %d\n", Student[i].age);
            printf("Branch: %s\n", Student[i].branch);
            found = 1;
            break; // Exit loop if found
        }
    }

    if (!found) {
        // Reset the file pointer to the beginning
        rewind(file);

        // Search in the students array
        for (int i = 0; i < studentCount; i++) {
            fscanf(file, "\nName of the student: %49[^\n]\n", students[i].name);
            fscanf(file, "Register Number of the student: %d\n", &students[i].reg_no);
            fscanf(file, "Age: %d\n", &students[i].age);
            fscanf(file, "Branch: %s\n", students[i].branch);

            // Convert the name to lowercase for comparison
            char lowerName[50];
            strcpy(lowerName, students[i].name);
            toLowerCase(lowerName);

            // Compares entered name with existing data
            if (strcmp(lowerName, sName) == 0) {
                printf("\nName of the student: %s\n", students[i].name);
                printf("Register Number of the student: %d\n", students[i].reg_no);
                printf("Age: %d\n", students[i].age);
                printf("Branch: %s\n", students[i].branch);
                found = 1;
                break; // Exit loop if found
            }
        }
    }

    fclose(file);

    if (!found) {
        printf("Student data not found\n");
    }
    return found;
}
