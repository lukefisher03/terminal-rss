#ifndef RSS_XML_TAG_H
#define RSS_XML_TAG_H

#include "d_array.h"


typedef enum tag_type { TAG_OPEN, TAG_CLOSE, TAG_SELF_CLOSE, TAG_IGNORE } tag_type;

struct rss_xml_attr {
    char    *name;
    char    *value;
};

struct rss_xml_tag {
    char                    *name;
    tag_type                type;
    struct rss_xml_attr     **attrs;
    size_t                  attr_count;
};

struct rss_xml_tag *build_rss_xml_tag(char *tag, size_t length);
void print_rss_xml_tag(struct rss_xml_tag *t);

int _parse_tag_attrs(struct rss_xml_tag *t, char *tag_str, size_t length);

#endif