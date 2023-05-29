GPP = g++
FLAGS = -Wall
INCLUDE = -I/usr/include/curl
LIB = -L/usr/lib/x86_64-linux-gnu

all : 
	make main
	make run

run :
	./bin/main

main : build/src/main.o build/src/log.o build/src/parser.o build/src/fileLocalise.o build/src/translate.o
	$(GPP) $(FLAGS) $(LIB) -o bin/main build/src/main.o build/src/log.o build/src/parser.o build/src/fileLocalise.o build/src/translate.o -lcurl

build/src/main.o : src/main.cpp
	$(GPP) $(FLAGS) $(INCLUDE) -c -o build/src/main.o src/main.cpp

build/src/log.o : src/log.cpp
	$(GPP) $(FLAGS) -c -o build/src/log.o src/log.cpp

build/src/parser.o : src/parser.cpp
	$(GPP) $(FLAGS) -c -o build/src/parser.o src/parser.cpp

build/src/fileLocalise.o : src/fileLocalise.cpp
	$(GPP) $(FLAGS) $(INCLUDE) -c -o build/src/fileLocalise.o src/fileLocalise.cpp

build/src/translate.o : src/translate.cpp
	$(GPP) $(FLAGS) $(INCLUDE) -c -o build/src/translate.o src/translate.cpp