GPP = g++
FLAGS = -wall

all : 
	make main
	make run

run :
	./main

main : build/main.o build/parser.o build/localise.o build/translate.o
	$(GPP) $(FLAGS) -o main.exe build/main.o build/parser.o build/localise.o build/translate.o

build/main.o : main.cpp
	$(GPP) $(FLAGS) -c -o build/main.o main.cpp

build/parser.o : src/parser.cpp
	$(GPP) $(FLAGS) -c -o build/parser.o src/parser.cpp

build/localise.o : src/localise.cpp
	$(GPP) $(FLAGS) -c -o build/localise.o src/localise.cpp

build/translate.o : src/translate.cpp
	$(GPP) $(FLAGS) -c -o build/translate.o src/translate.cpp
