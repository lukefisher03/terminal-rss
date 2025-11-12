# Parsing RSS XML
This document outlines some notes and general ideas with parsing RSS XML. This supports RSS 2.0

## Design Overview
This XML parser has no need to build a DOM. We're never going to traverse it again, we just want to collect a list of articles.

Each RSS element is represented by a struct. 

## Process
- Read the XML document character by character.
- Detect RSS XML tags via opening and closing arrows.
- Parse the content between them
- 

## List of RSS XML tags
Below is a list of all the RSS XML tags. Pulled from [here](https://www.rssboard.org/rss-draft-1#elements)

- rss
- channel
    - description
    - link
    - title
    - category
    - cloud
    - copyright
    - docs
    - generator
    - image
        - link
        - title
        - url
        - description
        - height
        - width
    - language
    - lastBuildDate
    - managingEditor
    - pubDate
    - rating
    - skipDays
        - day
    - skipHours
        - hour
    - textInput
        - description
        - link
        - name
        - title
    - ttl
    - webMaster
    - item
        - author
        - category
        - comments
        - description
        - enclosure
        - guid
        - link
        - pubDate
        - source
        - title