prog:main.o image.o function.o perso.o bk.o minmap.o ing_txt.o ing_ph.o ennemie.o
	gcc main.o image.o function.o perso.o bk.o minmap.o ing_txt.o ing_ph.o ennemie.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm -o prog  -g

main.o:main.c
	gcc -c main.c  -g
function.o:function.c
	gcc -c function.c -g
image.o:image.c
	gcc -c image.c -g
perso.o:perso.c
	gcc -c perso.c -g
bk.o:bk.c
	gcc -c bk.c -g
minmap.o:minmap.c
	gcc -c minmap.c -g
ing_txt.o:ing_txt.c
	gcc -c ing_txt.c -g
ing_ph.o:ing_ph.c
	gcc -c ing_ph.c -g
ennemie.o:ennemie.c
	gcc -c ennemie.c -g

clean:
	rm -rf *.o

