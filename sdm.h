#ifndef SDM_H
#define SDM_H
#define Max_students 100

#include <stdio.h>

struct student{
    char name[50];
    int reg_no;
    int age;
    char branch[50];
};

struct student Student[Max_students] = {{"stdA",01,20,"CSE"},{"stdB",02,21,"CSE"},{"stdC",03,20,"ECE"},{"stdD",04,19,"CSE"},
{"stdE",05,20,"ECE"},{"stdF",06,21,"CSE"},{"stdG",07,21,"ECE"},{"stdH",0x8,20,"CSE"},
{"stdI",0x9,19,"CSE"},{"stdJ",0xA,20,"EEE"},{"stdK",0xB,21,"ECE"},{"stdL",0xC,20,"CSE"},
{"stdM",0xD,19,"ECE"},{"stdN",0xE,21,"ECE"},{"stdO",0xF,22,"CSE"}};

int viewRecord();
int searchStudent();
void addStudent();
void deleteRecord();

#endif
