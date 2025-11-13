# Terminal RSS Aggregator
A lightweight RSS Aggregator that runs in your terminal. Written in C

## Features
TBD

## TODO
### Not Started
- [ ] Add mechanism for storing RSS feeds (Database? Local files? Haven't figure out the scope yet. Database seems excessively complicated).
- [ ] Periodically fetch stored RSS feed links.
- [ ] UI.
    - Is the UI just going to be text? 
    - Will it be a legit TUI?
    - GUI? (doubt this will happen, but recording for completeness)
- [ ] Support windows?

### In Progress
- [ ] Parse RSS XML. (80% complete)
    - [ ] Handle CDATA properly. Should I figure out some way to display the HTML or just convert to plaintext?
- [ ] Build API for fetching RSS feeds using C network sockets.

### Complete
- [ ] Break down RSS into tag objects.
- [ ] Get HTTPS working with C network sockets.