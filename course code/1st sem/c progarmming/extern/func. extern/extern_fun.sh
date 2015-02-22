#!/bin/sh

	rm -f a.out
	gcc extern_fun.c extern_main.c
	./a.out

exit 0

