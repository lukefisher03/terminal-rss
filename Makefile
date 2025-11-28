CLANG = clang -std=gnu11 -O0 -g

CFLAGS += $(shell pkg-config --cflags openssl)
LDFLAGS += $(shell pkg-config --libs libssl libcrypto)

PARSER = src/parser


socket_test: src/socket_test.c
	${CLANG} ${CFLAGS} src/socket_test.c ${LDFLAGS} -o main

run_socket_test: socket_test
	./main

main: src/main.c \
	  src/utils.c \
	  src/utils.h \
	  src/list.h src/list.c \
	  ${PARSER}/xml_rss.h \
	  ${PARSER}/xml_rss.c \
	  ${PARSER}/node.h \
	  ${PARSER}/node.c
	${CLANG} -o main src/main.c src/utils.c ${PARSER}/xml_rss.c src/list.c ${PARSER}/node.c

run_main: main
	./main