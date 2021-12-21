all: build
./Onegin.exe

build: Onegin.o main.o
  gcc Onegin.o main.o -o Onegin.exe
  
Onegin.o: Onegin.cpp Onegin.h
  g++ -c Onegin.c
  
 main.o: main.c
  g++ -c main.c
  
clean:
  del /f *.o
  del /f *.exe
