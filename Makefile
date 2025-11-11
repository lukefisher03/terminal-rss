CLANG = clang -std=c99 -O0 -g

CFLAGS += $(shell pkg-config --cflags openssl)
LDFLAGS += $(shell pkg-config --libs libssl libcrypto)

socket_test: socket_test.c
	${CLANG} ${CFLAGS} socket_test.c ${LDFLAGS} -o main

xml_tree: xml_tree.c
	${CLANG} -o main xml_tree.c