GPP = g++
FLAGS = -Wall
INCLUDE = -I/usr/include
SRC_INCLUDE = -I../src/
LIB = -L/usr/lib/x86_64-linux-gnu

all : 
	make main
	make run

run :
	./bin/main


test : bin/mainTest.exe build/test/main.o build/test/log.o build/src/log.o build/test/parser.o build/src/parser.o
	$(GPP) $(FLAGS) $(SRC_INCLUDE) -o bin/mainTest.exe build/test/main.o build/test/log.o build/src/log.o build/test/parser.o build/src/parser.o

build/src/main.o : test/main.cpp 
	$(GPP) $(FLAGS) $(SRC_INCLUDE) -c -o build/test/main.o test/main.cpp

build/test/log.o : test/log.cpp
	$(GPP) $(FLAGS) $(SRC_INCLUDE) -c -o build/test/log.o test/log.cpp

build/test/parser.o : test/parser.cpp
	$(GPP) $(FLAGS) $(SRC_INCLUDE) -c -o build/test/parser.o test/parser.cpp


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
