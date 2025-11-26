#include "utils.h"
#include "xml_rss.h"
#include "dynamic_string.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    size_t size;
    // char *rss = file_to_string("test/smart_less.xml", &size);
    char *rss = file_to_string("test/stack_overflow.xml", &size);
    struct node *tree = construct_parse_tree(rss, size);
    print_parse_tree(tree, 0);
    free(rss);
}