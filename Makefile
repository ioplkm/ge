CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -pipe -O3 -s -std=c11 -flto=thin -shared -fPIC -D_POSIX_C_SOURCE=200112L
all: src/* inc/*
	wayland-scanner client-header < /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml > inc/xdg-shell.h
	wayland-scanner private-code < /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml > src/xdg-shell.c
	$(CC) $(CFLAGS) src/* -o libge.so
install: libge.so
	mkdir -p /usr/local/include/ge
	install -m755 libge.so /usr/local/lib64
	install -m755 inc/* /usr/local/include/ge
