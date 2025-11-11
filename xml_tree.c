#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define MAX_FILE_SIZE   5000000 // Maximum RSS feed page size is 5MB
#define CHUNK_SIZE      4096

typedef struct TreeNode {
    char            *tag_name;
    char            *text;
    size_t          child_count;
    struct TreeNode **child_nodes;
} TreeNode;


int main(int argc, char *argv[]) {
    char *rss = file_to_string("test.xml");
    free(rss);
}
