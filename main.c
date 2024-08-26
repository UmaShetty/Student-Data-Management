#include <stdio.h>
#include "sdm.h"
#include "viewRecord.c"
#include "searchStudent.c"
#include "addStudent.c"
#include "deleteRecord.c"

// Function to display menu options
void displayMenu() {
    printf("STUDENT DATABASE MANAGEMENT\n");
    printf("---------------------------\n");
    printf("1. Add a Student\n");
    printf("2. View Student Records\n");
    printf("3. Search for a student\n");
    printf("4. Delete a Student\n");
    printf("5. Exit\n");
}

int getValidChoice() {
    int choice;
    char ch;
    while (1) {
        printf("\n\nEnter your choice: ");
        if (scanf("%d", &choice) == 1)
        {

            ch = getchar();
            if (ch == '\n')
            {
                return choice;
            }
            else
            {
                printf("Invalid Choice. Please enter a valid option.\n");

                while (ch != '\n' && ch != EOF)
                {
                    ch = getchar();
                }
            }
        }
        else
        {
            printf("Invalid Choice. Please enter a valid option.\n");
            while (getchar() != '\n');
        }
    }
}

int main() {
    int choice;
    displayMenu();

    do {
        choice = getValidChoice();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewRecord();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("......Exiting the Program.......\n");
                break;
            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
