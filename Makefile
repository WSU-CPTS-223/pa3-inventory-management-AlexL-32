# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g -O0

# Executables
TARGET = build.out
SIMPLE_TEST_TARGET = simple_test

# Object lists
OBJS = main.o data.o
SIMPLE_TEST_OBJS = simpleTest.o data.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp data.h list.h hashTable.h node.h
	$(CXX) $(CXXFLAGS) -c main.cpp

data.o: data.cpp data.h list.h
	$(CXX) $(CXXFLAGS) -c data.cpp

# cassert test target
$(SIMPLE_TEST_TARGET): $(SIMPLE_TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(SIMPLE_TEST_TARGET) $(SIMPLE_TEST_OBJS)

simpleTest.o: simpleTest.cpp data.h list.h hashTable.h node.h
	$(CXX) $(CXXFLAGS) -c simpleTest.cpp

# Run tests
run_tests: $(SIMPLE_TEST_TARGET)
	./$(SIMPLE_TEST_TARGET)


clean:
	rm -f *.o $(TARGET) $(SIMPLE_TEST_TARGET)

.PHONY: all run_tests clean
