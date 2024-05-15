#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_t create_student(char *_id, char *_name, char *_year, char *_gender)
{
    FILE *fs;
    fs = fopen("storage/student-repository.txt", "r");
    if (fs == NULL)
    {
        printf("File not found\n");
    }
    fprintf(fs, "%s|%s|%s|%s\n", _id, _name, _year, _gender);
    fclose(fs);
    
    struct student_t s;
    strcpy(s.id, _id);
    strcpy(s.name, _name);
    strcpy(s.year, _year);
    if (strcmp(_gender, "male") == 0)
    {
        s.gender = GENDER_MALE;
    }
    else if (strcmp(_gender, "male") == 0)
    {
        s.gender = GENDER_FEMALE;
    }

    s.dorm = malloc(sizeof(struct dorm_t));
    s.dorm = NULL;
    return s;
}
void print_student(struct student_t *_student, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (_student[i].gender == GENDER_MALE)
        {
            printf("%s|%s|%s|male\n", _student[i].id, _student[i].name, _student[i].year);
        }
        else if (_student[i].gender == GENDER_FEMALE)
        {
            printf("%s|%s|%s|female\n", _student[i].id, _student[i].name, _student[i].year);
        }
    }
}
void print_student_detail(struct student_t *_student, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (_student[i].dorm == NULL)
        {
            if (_student[i].gender == GENDER_MALE)
            {
                printf("%s|%s|%s|male|unassigned\n", _student[i].id, _student[i].name, _student[i].year);
            }
            else if (_student[i].gender == GENDER_FEMALE)
            {
                printf("%s|%s|%s|female|unassigned\n", _student[i].id, _student[i].name, _student[i].year);
            }
        }
        else
        {
            if (_student[i].gender == GENDER_MALE)
            {
                printf("%s|%s|%s|male|%s\n", _student[i].id, _student[i].name, _student[i].year, _student[i].dorm->name);
            }
            else if (_student[i].gender == GENDER_FEMALE)
            {
                printf("%s|%s|%s|female|%s\n", _student[i].id, _student[i].name, _student[i].year, _student[i].dorm->name);
            }
        }
    }
}
void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)
{
    if (_dorm->residents_num < _dorm->capacity)
    {
        if (_student->gender == _dorm->gender)
        {
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}

    void student_leave(struct student_t *siswa, struct dorm_t *_dorm
{
    if (siswa->dorm != NULL)
    {
      _dorm->residents_num--;
        siswa->dorm = NULL;
    }
}
