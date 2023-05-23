GPP = g++
FLAGS = -Wall
LIB = -L lib\curl-8.1.0_1-win64-mingw\lib
INCLUDE = -I lib\curl-8.1.0_1-win64-mingw\include

all : 
	make main
	make run

run :
	./main

main : build/main.o build/log.o build/parser.o build/fileLocalise.o build/translate.o
	$(GPP) $(FLAGS) $(LIB) -o main.exe build/main.o build/log.o build/parser.o build/fileLocalise.o build/translate.o -lcurl

build/main.o : main.cpp
	$(GPP) $(FLAGS) $(INCLUDE) -c -o build/main.o main.cpp

build/log.o : src/log.cpp
	$(GPP) $(FLAGS) -c -o build/log.o src/log.cpp

build/parser.o : src/parser.cpp
	$(GPP) $(FLAGS) -c -o build/parser.o src/parser.cpp

build/fileLocalise.o : src/fileLocalise.cpp
	$(GPP) $(FLAGS) $(INCLUDE) -c -o build/fileLocalise.o src/fileLocalise.cpp

build/translate.o : src/translate.cpp
	$(GPP) $(FLAGS) $(INCLUDE) -c -o build/translate.o src/translate.cpp