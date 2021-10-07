# -*- Makeflie -*-
UltimaThule: main.c
	gcc -Wall -std=c99 -Wno-missing-braces main.c -o UltimaThule -s -static -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm