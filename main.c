#include "utils.h"
#include "xml_rss.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    size_t size;
    char *rss = file_to_string("test/stack_overflow.xml", &size);
    struct xml_node *feed = construct_tree(rss, size);
    free(rss);
}