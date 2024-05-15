#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{
    char name[100];
    char nim[40];
    char gender[100];
    char year[5];
    char dormname[100];
};

struct student_t create_student(char *input);

void print_student_detail(struct student_t mhs);

int find_id(char *nim, int zstd, struct student_t *mhs);

void leave_student(struct dorm_t *drm, struct student_t *mhs, char *nim, char *asrama, int zstd, int zdrm, int find_id(char *nim,int zstd, struct student_t *mhs), int find_dorm(char *asrama, int zdrm, struct dorm_t *drm));

void assign_student(struct dorm_t *drm, struct student_t *mhs, char *asrama, int zstd, int  drm, int find_id(char *nim, int zstd, struct student_t *mhs), int find_dorm(char *asrama, int zdrm, struct dorm_t *drm));

#endif
