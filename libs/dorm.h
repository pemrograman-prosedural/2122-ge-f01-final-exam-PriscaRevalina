#ifndef DORM_H
#define DORM_H

#include "gender.h"

struct dorm_t
{
  char name[20];
  unsigned short capacity;
  enum gender_t gender;
  unsigned short residents_num;
};

void create_dorm(struct dorm_t *_dorm, char *_name, unsigned short _capacity, enum gender_t _gender);
void print_dorm(struct dorm_t *_dorm, int count);
void print_dorm_detail(struct dorm_t *_dorm, int count);
#endif

