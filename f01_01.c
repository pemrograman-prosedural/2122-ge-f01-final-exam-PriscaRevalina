// 12S23006 - Cardolan Sinaga
// 12S23039 - Prisca Manurung

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"
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
        if (strcmp(data, "---") == 0)
        {
            break;
        }
        else if (strcmp(data, "student-print-all") == 0)
        {
            print_student(students, std);
        }
        else if (strcmp(data, "student-print-all-detail") == 0)
        {
            print_student_detail(students, std);
        }
        else if (strcmp(data, "student-add") == 0)
        {
            data = strtok(NULL, "#");
            strcpy(id, data);
            data = strtok(NULL, "#");
            strcpy(student_name, data);
            data = strtok(NULL, "#");
            strcpy(year, data);
            data = strtok(NULL, "#");
            if (strcmp(data, "male") == 0)
            {
                students[std] = create_student(id, student_name, year, GENDER_MALE);
            }
            else if (strcmp(data, "female") == 0)
            {
                students[std] = create_student(id, student_name, year, GENDER_FEMALE);
            }
            std++;
        }
        else if (strcmp(data, "dorm-print-all-detail") == 0)
        {
            print_dorm(dorms, dr);
        }
        else if (strcmp(input, "dorm-add") == 0)
        {
            data = strtok(NULL, "#");
            strcpy(dorm_name, data);
            data = strtok(NULL, "#");
            capacity = atoi(data);
            data = strtok(NULL, "#");
            if (strcmp(data, "male") == 0)
            {
                dorms[dr] = create_dorm(dorm_name, capacity, GENDER_MALE);
            }
            else if (strcmp(data, "female") == 0)
            {
                dorms[dr] = create_dorm(dorm_name, capacity, GENDER_FEMALE);
            }
            dr++;
        }
        else if (strcmp(data, "assign-student") == 0)
        {
            data = strtok(NULL, "#");
            strcpy(id, data);
            data = strtok(NULL, "#");
            strcpy(dorm_name, data);
            idx_s = 0;
            idx_d = 0;
            for (int i = 0; i < std; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    idx_s = i;
                    break;
                }
            }
            for (int i = 0; i < std; i++)
            {
                if (strcmp(dorms[i].name, dorm_name) == 0)
                {
                    idx_d = i;
                    break;
                }
            }
            assign_student(&students[idx_s], &dorms[idx_d]);
        }

        else if (strcmp(data, "student-leave") == 0)
        {
            data = strtok(NULL, "#");
            strcpy(id, data);
            idx_s = 0;
            idx_d = 0;
            for (int i = 0; i < std; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    idx_s = i;
                    break;
                }
            }
            for (int i = 0; i < dr; i++)
            {
                if (strcmp(students[idx_s].dorm->name, dorms[i].name) == 0)
                {
                    idx_d = i;
                    break;
                }
            }

            leave_student(&students[idx_s], &dorms[idx_d]);
        }
    } while (1);
    free(students);
    free(dorms);
    return 0;
}


