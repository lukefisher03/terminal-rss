#ifndef XML_RSS_H
#define XML_RSS_H

#include "list.h"

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

struct xml_node {
    struct list *children; // Number of children.
    char *name;            // Name of the element.
    char *text_content;    // The text content it contains.
};

enum TAG_TYPE {
    TAG_OPEN,
    TAG_CLOSE,
    TAG_SELF_CLOSE,
};

struct tag {
    char            *name;
    enum TAG_TYPE   tag_type;   // True is opening, false is closing.
                                // We ignore self-closing tags.
    size_t          total_length;
};

struct xml_node *construct_tree(char *xml, size_t length);

struct tag *read_tag(char *str, size_t length);

bool is_termination_char(char c);

struct tag *tag_init();

struct xml_node *xml_node_init();

void dfs(struct xml_node *root);

#endif