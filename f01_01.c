// 12S23006 - Cardolan Sinaga
// 12S23039 - Prisca Manurung

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"

int compare(char *str1, char *str2)
{
    if (strlen(str1) != strlen(str2))
    {
        return 0;
    }
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}

int main(int _argc, char **_argv)
{
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));
    char input[100];
    char id[12];
    char student_name[40];
    char year[5];
    char dorm_name[40];
    unsigned short capacity;
    char *data;
    int idx_s, idx_d;
    int std = 0, dr = 0;
    do
    {
        fflush(stdin);
        input[0] = '\0';
        int c = 0;
        while (1)
        {
            char x = getchar();
            if (x == '\r')
            {
                continue;
            }
            if (x == '\n')
            {
                break;
            }
            input[c] = x;
            input[++c] = '\0';
        }
        data = strtok(input, "#");
        if (compare(data, "---"))
        {
            break;
        }
        else if (compare(data, "student-print-all-detail"))
        {
            print_student_detail(students, std);
        }
        else if (compare(data, "student-add"))
        {
            data = strtok(NULL, "#");
            strcpy(id, data);
            data = strtok(NULL, "#");
            strcpy(student_name, data);
            data = strtok(NULL, "#");
            strcpy(year, data);
            data = strtok(NULL, "#");
            if (compare(data, "male"))
            {
                create_student(&students[std], id, student_name, year, GENDER_MALE);
            }
            else if (compare(data, "female"))
            {
                create_student(&students[std], id, student_name, year, GENDER_FEMALE);
            }
            std++;
        }
        else if (compare(input, "dorm-add"))
        {
            data = strtok(NULL, "#");
            strcpy(dorm_name, data);
            data = strtok(NULL, "#");
            capacity = atoi(data);
            data = strtok(NULL, "#");
            if (compare(data, "male"))
            {
                create_dorm(&dorms[dr], dorm_name, capacity, GENDER_MALE);
            }
            else if (compare(data, "female"))
            {
                create_dorm(&dorms[dr], dorm_name, capacity, GENDER_FEMALE);
            }
            dr++;
        }
        else if (compare(data, "assign-student"))
        {
            data = strtok(NULL, "#");
            strcpy(id, data);
            data = strtok(NULL, "#");
            strcpy(dorm_name, data);
            idx_s = 0;
            idx_d = 0;
            for (int i = 0; i < std; i++)
            {
                if (compare(students[i].id, id))
                {
                    idx_s = i;
                    break;
                }
            }
            for (int i = 0; i < std; i++)
            {
                if (compare(dorms[i].name, dorm_name))
                {
                    idx_d = i;
                    break;
                }
            }
            assign_student(&students[idx_s], &dorms[idx_d]);
        }

        else if (compare(data, "student-leave"))
        {
            data = strtok(NULL, "#");
            for (int i = 0; i < std; i++)
            {
                if (compare(students[i].id, data))
                {
                    strcpy(students[i].dorm, "left");
                    break;
                }
            }
        }
    } while (1);
    free(students);
    free(dorms);
    return 0;
}
