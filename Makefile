CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g
SANITIZE_FLAGS = -fsanitize=address

TARGET = csv_demo
TEST_TARGET = csv_tests

SOURCES = main.cpp csvreader.cpp product.cpp
HEADERS = main.h csvreader.h product.h
TEST_SOURCES = test_main.cpp test.cpp csvreader.cpp product.cpp
TEST_HEADERS = test.h csvreader.h product.h

.PHONY: all run test sanitize clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

$(TEST_TARGET): $(TEST_SOURCES) $(TEST_HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

sanitize:
	$(CXX) $(CXXFLAGS) $(SANITIZE_FLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)_asan
	./$(TEST_TARGET)_asan

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(TEST_TARGET)_asan
