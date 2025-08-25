CXX := g++

CXXFLAGS := --std=c++11

MAIN_FILES = $(shell grep -El "main()" `find -name "*.cpp" -type f`)

NOT_MAIN_FILES = $(shell grep -L "main()" `find -name "*.cpp" -type f`)
OBJS = $(NOT_MAIN_FILES:.cpp=.o)

.PHONY:all
all: haha.o hehe.o nohehe.o powerful restoreExec

hehe.o: hehe.cpp card.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

haha.o: haha.cpp player.h card.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

nohehe.o: nohehe.cpp deck.h card.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

restoreExec: restore.cpp hehe.o nohehe.o haha.o 
	$(CXX) $(CXXFLAGS) $^ -o restore


powerful: powerful.cpp hehe.o
	$(CXX) $(CXXFLAGS) $^ -o powerful

.PHONY:restore
restore:
	rm -f $(wildcard *.o) powerful restore

