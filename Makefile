all : prog clean
prog : main.o enigme.o uti.o background.o enemy.o settings.o character.o 
	@echo "building..."
	gcc main.c  enigme.c uti.c background.c enemy.c settings.c character.c  -o prog  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
clean:
	@echo "cleaning up..."
	rm *.o
