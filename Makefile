GPP = g++
FLAGS = -Wall
INCLUDE = -I/usr/include
LIB = -L/usr/lib/x86_64-linux-gnu
SRC = build/src/main.o build/src/log.o build/src/parser.o build/src/fileLocalise.o build/src/translate.o
TEST = build/test/main.o build/test/log.o build/test/parser.o build/test/fileLocalise.o

all : 
	make main
	make run

run :
	./bin/main

test : $(SRC) $(TEST)
	$(GPP) $(FLAGS) -o bin/mainTest $(SRC) $(TEST) -lcurl
	./bin/mainTest

build/test/main.o : test/main.cpp 
	$(GPP) $(FLAGS) -c -o build/test/main.o test/main.cpp

build/test/log.o : test/log.cpp
	$(GPP) $(FLAGS) -c -o build/test/log.o test/log.cpp

build/test/parser.o : test/parser.cpp
	$(GPP) $(FLAGS) -c -o build/test/parser.o test/parser.cpp

build/test/fileLocalise.o : test/fileLocalise.cpp
	$(GPP) $(FLAGS) -c -o build/test/fileLocalise.o test/fileLocalise.cpp

main : $(SRC)
	$(GPP) $(FLAGS) $(LIB) -o bin/main $(SRC) -lcurl

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