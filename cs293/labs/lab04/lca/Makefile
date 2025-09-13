# # Makefile for compiling main.cpp

# # Compiler
# CC = g++
# # Compiler flags
# CFLAGS = -g -std=c++20 -Wall -Wextra
# # Source files
# SOURCE = tree.cpp findlca.cpp main.cpp
# # Executable name
# EXECUTABLE = tree

# all: $(EXECUTABLE)

# $(EXECUTABLE): $(SOURCE) main.cpp
# 	$(CC) $(CFLAGS) $(SOURCE) -o $(EXECUTABLE)

# findlca: $(EXECUTABLE)
# 	./tree 1 > results.txt
# 	diff results.txt expectedOutput/outputs.txt

# interactive: $(EXECUTABLE)
# 	./tree 0

# clean:
# 	rm -f $(EXECUTABLE) results.txt
# 	rm -f *~

# .PHONY: clean

# Makefile for CRC Lab
SHELL := /bin/bash

# Compiler and flags - Modern C++20
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++20

# Executable name
EXEC = lca

# Source files
# (crc-functions.cpp is intentionally present but can be ignored by students)
SOURCES = $(EXEC).cpp main.cpp tree.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Test configuration
NUM_TEST_CASES = 10
TCDIR = tests

# Default target
all: build runtests

# Build target
build: $(EXEC)

# Link executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Compile object files
%.o: %.cpp *.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run all test cases
runtests: $(EXEC)
	@echo -e "Running Test Cases"
	@for i in `seq 1 $(NUM_TEST_CASES)`; do \
		echo -e "\n\033[0;36mTestcase $$i\033[0m"; \
		echo -e "./$(EXEC) < $(TCDIR)/test$$i/input.txt"; \
		./$(EXEC) < $(TCDIR)/test$$i/input.txt > output.txt; \
		if diff -Bw output.txt $(TCDIR)/test$$i/output.txt > /dev/null; then \
			echo -e "\033[0;32mPASSED\033[0m"; \
		else \
			echo -e "diff -Bw output.txt $(TCDIR)/test$$i/output.txt";\
			diff -Bw output.txt $(TCDIR)/test$$i/output.txt; \
			echo -e "\033[0;31mFAILED\033[0m"; \
		fi \
	done
	@rm -f output.txt

interactive: $(EXEC)
	./$(EXEC) 0


# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(EXEC) output.txt
	find . -type f -name '*~' -delete

.PHONY: all build runtests clean
