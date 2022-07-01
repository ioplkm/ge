CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -pipe -O3 -s -std=c99 -flto=thin -shared -fPIC
all: src/fb.c
	$(CC) $(CFLAGS) src/fb.c -o libfb.so
install: fb.so
	install -m755 libfb.so /usr/local/lib64
	install -m755 inc/fb.h /usr/local/include
