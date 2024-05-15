#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, char *_gender)
{
    FILE *fd;
    fd = fopen("storage/dorm-repository.txt", "r");
    if (fd == NULL)
    {
        printf("File not found\n");
    }
    fprintf(fd, "%s|%d|%s\n", _name, _capacity, _gender);

    struct dorm_t d;
    strcpy(d.name, _name);
    d.capacity = _capacity;
    if (strcmp(_gender, "male") == 0)
    {
        d.gender = GENDER_MALE;
    }
    else if (strcmp(_gender, "male") == 0)
    {
        d.gender = GENDER_FEMALE;
    }
    d.residents_num = 0;
    return d;
}

void print_dorm(struct dorm_t *_dorm, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (_dorm[i].gender == GENDER_MALE)
        {
            printf("%s|%d|male\n", _dorm[i].name, _dorm[i].capacity);
        }
        else if (_dorm[i].gender == GENDER_FEMALE)
        {
            printf("%s|%d|female\n", _dorm[i].name, _dorm[i].capacity);
        }
    }
}
void print_dorm_detail(struct dorm_t *_dorm, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (_dorm[i].gender == GENDER_MALE)
        {
            printf("%s|%d|male|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        }
        else if (_dorm[i].gender == GENDER_FEMALE)
        {
            printf("%s|%d|female|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        }
    }
}