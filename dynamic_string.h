#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <stdio.h>
#include <stdbool.h>

struct ds { // The name `ds` stands for dynamic string
    char    *str;
    size_t  capacity;
    size_t  length;
};

struct ds *ds_init(const char * s);
struct ds *ds_clone(const struct ds *s);
struct ds *ds_append(struct ds *s1, const char *s2);
void ds_reset(struct ds *s);
void ds_free(struct ds *s);

#endif