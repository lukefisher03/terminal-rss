#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "rss_xml_tag.h"

#define MAX_FILE_SIZE 5000000 // Maximum RSS feed page size is 5MB
#define CHUNK_SIZE 4096
#define MAX_TAG_SIZE 4096


// An article must have at the very least a title OR a description.
struct article {
    char    *title;
    int     pub_date;
    char    *author;
    char    *description;
    char    *guid;
    char    *text_content;
};

struct rss_feed {
    int             last_updated;
    int             article_count;
    char            *name;
    char            *source_url;
    struct article  **items;
};

struct rss_feed *build_feed(char *xml, size_t size) {
    struct rss_feed *feed = calloc(1, sizeof(struct rss_feed));

    size_t i = 0;

    // while (i < size) {
    while (i < size) {
        char c = xml[i];
        if (c == '<') {
            char tag[MAX_TAG_SIZE]; // The tag name shouldn't exceed 128 characters.

            size_t tag_len = 0;

            bool reached_delimiter = false; // A boolean flag to make sure we stop storing the tag name.

            size_t j;
            for (j = i + 1; tag_len < MAX_TAG_SIZE && xml[j] != '>'; j++) {
                if (j >= size - 2) {
                    printf("No more characters! Invalid RSS!\n");
                    break;
                }
                
                tag[tag_len++] = xml[j];
            }
            
            tag[tag_len] = '\0';
            if (!tag_len) {
                continue;
            }
            printf("Raw Tag: %s\n", tag);
            struct rss_xml_tag *t = build_rss_xml_tag(tag, tag_len);
            print_rss_xml_tag(t);
        }
        i++;
    }

    feed->article_count = 5;

    printf("\nGot here\n");
    return feed;
}

int main(int argc, char *argv[]) {
    size_t size;
    char *rss = file_to_string("test.xml", &size);
    struct rss_feed *feed = build_feed(rss, size);
    printf("Feed article count: %i\n", feed->article_count);
    free(rss);
}