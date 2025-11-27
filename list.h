#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>

struct list {
    size_t capacity;
    size_t count;
    void **elements;
};

struct list *list_init(void);

bool list_append(struct list *stk, void *item);

bool list_is_empty(const struct list *stk);

void *list_pop(struct list *stk);

void *list_peek(const struct list *stk);

void list_clear(struct list *stk);

void list_free(struct list *stk);

#endif