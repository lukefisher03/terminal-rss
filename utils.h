#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 4096
#define MAX_FILE_SIZE 5000000

char *file_to_string(const char *path, size_t *size);

#endif