CC = g++
CFLAGS = -c -Wall
LIB = -lcurl
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
BIN_DIR = bin
MAIN_BUILD = build/src/main.o build/src/parser.o build/src/fileLocalise.o build/src/translate.o build/src/log.o
TEST_BUILD = build/test/main.o build/test/parser.o build/test/fileLocalise.o build/src/parser.o build/src/fileLocalise.o build/src/translate.o

main: $(BIN_DIR)/main

test: $(BIN_DIR)/test

$(BIN_DIR)/main: $(MAIN_BUILD)
	$(CC) $^ -o $@ $(LIB)
	./$(BIN_DIR)/main

$(BIN_DIR)/test: $(TEST_BUILD)
	$(CC) $^ -o $@ $(LIB)
	./$(BIN_DIR)/test

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	find $(BUILD_DIR)/$(TEST_DIR) $(BUILD_DIR)/$(SRC_DIR) $(BIN_DIR) -type f ! -name ".keep" -delete 2>/dev/null || true