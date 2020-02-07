#include <stdio.h>

typedef struct Student
{
    int roll;
    char name[20];
} Student;

int main(int argc, char *argv[])
{
    Student s1;
    Student *s = &s1;
    scanf("%d", &(s->roll));
    gets(s->name);
    printf("Name : %s \nRoll Number : %d", s->name, s->roll);
}