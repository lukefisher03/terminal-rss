#include "xml_rss.h"
#include "list.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

struct xml_node *construct_tree(char *xml, size_t length) {
    // Go through and detect closing and opening tags.

    struct xml_node *root = xml_node_init();
    struct list *stack = list_init();
    list_append(stack, root);

    size_t last_element_start = 0;

    size_t i = 0;
    while (i < length) {
        char *s = xml + i;
        size_t l = length - i;
        if (prefixcmp("<", s, l) && !prefixcmp("<!", s, l) && !prefixcmp("<?", s, l)) {
            struct tag *new_tag = read_tag(s, l);
            if (new_tag) {
                if (new_tag->tag_type == TAG_OPEN) {
                    struct xml_node *node = xml_node_init();
                    node->name = strndup(new_tag->name, strlen(new_tag->name));
                    struct xml_node *top = list_peek(stack);
                    list_append(top->children, node);
                    list_append(stack, node);
                    last_element_start = i+new_tag->total_length;

                } else if (new_tag->tag_type == TAG_CLOSE) {
                    
                    struct xml_node *v = list_pop(stack); // Pop off the stack
                    // Need to fix how I'm doing this lol.
                    v->text_content = strndup(xml + last_element_start + 1, i - last_element_start - 1);
                    
                }

                i += new_tag->total_length;
                free(new_tag->name);
                free(new_tag);
            }
        } else {
            i++;
        }
    }

    dfs(root);
    printf("Stack count: %lu\n", stack->count);
    return NULL;
}

void dfs(struct xml_node *root) {
    printf("Node: %s\n", root->name);
    printf("Text content: %s\n", root->text_content);
    printf("Children count: %lu\n", root->children->count);

    for (size_t i = 0; i < root->children->count; i++) {
        dfs(root->children->elements[i]);
    }
}

struct tag *read_tag(char *str, size_t length) {
    struct tag *new_tag = tag_init();
    if (!new_tag) return NULL;
    
    size_t i = 1;
    if (str[i] == '/') {
        i++;
    }
    size_t offset = i;
    for (; i < length && !is_termination_char(str[i]); i++);
    new_tag->name = strndup(str+offset, i-offset);
    for (; i < length && str[i] != '>'; i++);

    if (i >= length) return NULL;

    if (str[1] == '/') {
        new_tag->tag_type = TAG_CLOSE;
    } else if (str[i - 1] == '/') {
        new_tag->tag_type = TAG_SELF_CLOSE;
    } else {
        new_tag->tag_type = TAG_OPEN;
    }

    new_tag->total_length = i;
    return new_tag;
}

bool is_termination_char(char c) {
    if (c == ' ' || c == ':' || c == '/' || c == '>') {
        return true;
    }
    return false;
}

struct tag *tag_init() {
    struct tag *new_tag = malloc(sizeof(struct tag));
    return new_tag ? new_tag : NULL;
}

struct xml_node *xml_node_init() {
    struct xml_node *new_node = calloc(1, sizeof(struct xml_node));
    if (!new_node) {
        return NULL;
    }
    new_node->children = list_init();
    return new_node;
}