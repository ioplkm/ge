CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -pipe -O3 -s -std=c99 -flto=thin -shared -fPIC
all: src/*
	$(CC) $(CFLAGS) src/* -o libge.so
install: libge.so
	mkdir -p /usr/local/include/ge
	install -m755 libge.so /usr/local/lib64
	install -m755 inc/* /usr/local/include/ge
