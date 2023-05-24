GPP = g++
FLAGS = -Wall

all : 
	make main
	make run

run :
	./bin/main

main : build/main.o build/log.o build/parser.o build/fileLocalise.o build/translate.o
	$(GPP) $(FLAGS) -o bin/main.exe build/main.o build/log.o build/parser.o build/fileLocalise.o build/translate.o -lcurl

build/main.o : src/main.cpp
	$(GPP) $(FLAGS) -c -o build/main.o src/main.cpp

build/log.o : src/log.cpp
	$(GPP) $(FLAGS) -c -o build/log.o src/log.cpp

build/parser.o : src/parser.cpp
	$(GPP) $(FLAGS) -c -o build/parser.o src/parser.cpp

build/fileLocalise.o : src/fileLocalise.cpp
	$(GPP) $(FLAGS) -c -o build/fileLocalise.o src/fileLocalise.cpp

build/translate.o : src/translate.cpp
	$(GPP) $(FLAGS) -c -o build/translate.o src/translate.cpp