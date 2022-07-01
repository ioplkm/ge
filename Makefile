CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -pipe -O3 -s -std=c99 -flto=thin -shared -fPIC
all: src/fb.c
	$(CC) $(CFLAGS) src/fb.c -o libge.so
install: libge.so
	mkdir -p /usr/local/include/ge
	install -m755 libge.so /usr/local/lib64
	install -m755 inc/fb.h /usr/local/include/ge
