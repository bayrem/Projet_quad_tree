## pour compiler on vas dans le fichier du projet et on execute les commandes suivantes : 
## make main
## ./main

CC=gcc
CFLAGS=-O2 -Wall `sdl-config --cflags`
LIBS=`sdl-config --libs` -lm -lSDL_ttf

%: graphics.o arbre.o mode_creation.o mode_manipulation.o %.c
	rm -f $@
	$(CC) $(CFLAGS) graphics.o arbre.o mode_creation.o mode_manipulation.o $@.c -o $@ $(LIBS)


graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	$(CC) $(CFLAGS) -c graphics.c

arbre.o: arbre.c arbre.h
	
	$(CC) $(CFLAGS) -c arbre.c
	
mode_creation.o: mode_creation.c mode_creation.h
	
	$(CC) $(CFLAGS) -c mode_creation.c
	
mode_manipulation.o: mode_manipulation.c mode_manipulation.h
	
	$(CC) $(CFLAGS) -c mode_manipulation.c
	
clean:
	rm -f *core
	rm -f *.o
	rm -f police.h
	rm -f exemple
	rm -f *.tar
