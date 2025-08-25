CXXFLAGS = -std=c++20

all :debug

debug : ./debug/array.o ./debug/onemore.o ./debug/onething.o ./debug/otherthing.o ./debug/program

./debug/array.o : array.cpp array.hpp
	g++ -g -c $< -o ./debug/array.o

./debug/onemore.o : onemore.cpp onemore.hpp otherthing.hpp onething.hpp array.hpp
	g++ -g -c $< -o ./debug/onemore.o

./debug/onething.o : onething.cpp onething.hpp array.hpp
	g++ -g -c $< -o ./debug/onething.o

./debug/otherthing.o : otherthing.cpp otherthing.hpp onething.hpp array.hpp
	g++ -g -c $< -o ./debug/otherthing.o

./debug/program : main.cpp ./debug/onemore.o ./debug/array.o ./debug/onething.o ./debug/otherthing.o
	g++ -g $^ -o ./debug/program

.PHONY : clean,debug
clean : 
	rm -rf ./debug/