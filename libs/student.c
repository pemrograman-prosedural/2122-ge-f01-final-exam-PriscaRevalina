#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create_student(struct student_t *_student, char *_id, char *_name, char *_year, enum gender_t _gender)
{
    strcpy(_student->id, _id);
    strcpy(_student->name, _name);
    strcpy(_student->year, _year);
    _student->gender = _gender;
    strcpy(_student->dorm, "unassigned");
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
        if (_student[i].gender == GENDER_MALE)
        {
            printf("%s|%s|%s|male|%s\n", _student[i].id, _student[i].name, _student[i].year, _student[i].dorm);
        }
        else if (_student[i].gender == GENDER_FEMALE)
        {
            printf("%s|%s|%s|female|%s\n", _student[i].id, _student[i].name, _student[i].year, _student[i].dorm);
        }
    }
}
void assign_student(struct student_t *_student, struct dorm_t *_dorm)
{
    if (_dorm->residents_num < _dorm->capacity)
    {
        if (_student->gender == _dorm->gender)
        {
            strcpy(_student->dorm, _dorm->name);
            _dorm->residents_num++;
        }
    }
}
void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm)
{
    if (_dorm->residents_num < _dorm->capacity)
    {
        if (_student->gender == _dorm->gender)
        {
            strcpy(_student->dorm, _dorm->name);
            _dorm->residents_num++;
            old_dorm->residents_num--;
        }
    }
}