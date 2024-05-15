// 12S23006 - Cardolan Sinaga
// 12S23039 - Prisca Manurung

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

typedef void (*CommandFunc)(char *, struct student_t **, int *, struct dorm_t **, int *);

typedef struct {
    char *name;
    CommandFunc func;
} Command;

void dorm_add(char *input, struct student_t **mhs, int *size, struct dorm_t **dorm, int *size2) {
    (*size2)++;
    *dorm = realloc(*dorm, *size2 * sizeof(struct dorm_t));
    (*dorm)[*size2 - 1] = create_dorm(input);
}

void dorm_print_all(char *input, struct student_t **mhs, int *size, struct dorm_t **dorm, int *size2) {
    for(int i = 0; i < *size2; i++) {
        print_dorm((*dorm)[i]);
    }
}

void student_add(char *input, struct student_t **mhs, int *size, struct dorm_t **dorm, int *size2) {
    (*size)++;
    *mhs = realloc(*mhs, *size * sizeof(struct student_t));
    (*mhs)[*size - 1] = create_student(input);
}

void student_print_all(char *input, struct student_t **mhs, int *size, struct dorm_t **dorm, int *size2) {
    for(int i = 0; i < *size; i++) {
        print_student((*mhs)[i]);

        // Check if student is assigned to a dorm
        int assigned = 0;
        for(int j = 0; j < *size2; j++) {
            if ((*mhs)[i].dorm != NULL && strcmp((*mhs)[i].dorm->name, (*dorm)[j].name) == 0) {
                assigned = 1;
                break;
            }
        }
        if (!assigned) {
            printf("|unassigned\n");
        } else {
            printf("\n");
        }
    }
}

int main(int _argc, char **_argv) {
    char input[100];
    int size = 0;
    char *token;
    struct student_t *mhs = NULL;
    int size2 = 0;
    struct dorm_t *dorm = NULL;

    Command commands[] = {
        {"dorm-add", dorm_add},
        {"dorm-print-all", dorm_print_all},
        {"student-add", student_add},
        {"student-print-all", student_print_all},
        {NULL, NULL}  // End marker
    };

    while(1) {
        fgets(input, sizeof input, stdin);
        if(input[strlen(input) - 1] == '\n' || input[strlen(input) - 1] == '\r') {
            input[strlen(input) - 1] = '\0';
        }

        token = strtok(input, "#");
        if(strcmp(token, "---") == 0) {
            break;
        }

        for(Command *cmd = commands; cmd->name != NULL; cmd++) {
            if(strcmp(token, cmd->name) == 0) {
                cmd->func(input, &mhs, &size, &dorm, &size2);
                break;
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        if (mhs[i].name != NULL) {
            free(mhs[i].name);
        }
        if (mhs[i].id != NULL) {
            free(mhs[i].id);
        }
        if (mhs[i].dorm != NULL) {
            if (mhs[i].dorm->name != NULL) {
                free(mhs[i].dorm->name);
            }
            free(mhs[i].dorm);
        }
    }
    free(mhs);
    free(dorm);
    return 0;
}
