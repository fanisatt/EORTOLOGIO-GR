 GReortes version 3.3


Here in Github you can see only the C code !

gcc -c geortes272.c -lSDL_bgi -lSDL2

gcc -c input86.c -lSDL_bgi -lSDL2

gcc -o GReortes3.3 geortes272.o input86.o -lSDL_bgi -lSDL2 -lm -no-pie

(Prerequisite for libraries to be installed : SDL_bgi (v.2.4.1) and SDL2.0)

Necessary additional files and tables : https://sourceforge.net/projects/eortologio-gr/
