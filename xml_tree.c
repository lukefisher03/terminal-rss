#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 5000000 // Maximum RSS feed page size is 5MB
#define CHUNK_SIZE 4096
#define MAX_TAG_SIZE 4096

typedef enum TAG_TYPE { TAG_OPEN, TAG_CLOSE, TAG_SELF_CLOSE, TAG_IGNORE } TAG_TYPE;

// An article must have at the very least a title OR a description.
typedef struct Article {
    char *title;
    int pub_date;
    char *author;
    char *description;
    char *text_content;
} Article;

typedef struct RSSFeed {
    int last_updated;
    int article_count;
    char *name;
    char *source_url;
    Article **items;
} RSSFeed;

RSSFeed *build_feed(char *xml, size_t size) {
    RSSFeed *feed = calloc(1, sizeof(RSSFeed));

    size_t i = 0;

    // while (i < size) {
    while (i < 5000) {
        char c = xml[i];
        if (c == '<') {
            char tag_name[MAX_TAG_SIZE]; // The tag name shouldn't exceed 4096
                                         // characters
            TAG_TYPE tag_type = TAG_OPEN;
            size_t tag_length = 0;
            bool found_delimiter = false; // A boolean flag to make sure we stop
                                          // storing the tag name.

            size_t j;
            char prev_char = ' ';
            for (j = i + 1; tag_length < MAX_TAG_SIZE && xml[j] != '>'; j++) {
                if (j >= size - 2) {
                    printf("No more characters! Invalid RSS!\n");
                    tag_type = TAG_IGNORE;
                    break;
                }
                
                if (prev_char == '<' && xml[j] == '/') {
                    // Detect a closing tag if you see the sequence `</`
                    tag_type = TAG_CLOSE;
                } else if (prev_char == '<' && xml[j] == '?') {
                    // Ignore XML processing instructions which begin with `<?`
                    tag_type = TAG_IGNORE;
                    break;
                }
            }
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
    RSSFeed *feed = build_feed(rss, size);
    printf("Feed article count: %i\n", feed->article_count);
    free(rss);
}