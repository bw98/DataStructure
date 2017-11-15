CXXFLAGS = -Wall -g -std=c++11
test : Huffman.o main.o
	g++ $(CXXFLAGS) Huffman.o main.o -o test
main.o : main.cpp Huffman.h
	g++ $(CXXFLAGS) -c main.cpp
Huffman.o : Huffman.cpp Huffman.h
	g++ $(CXXFLAGS) -c Huffman.cpp
clean : 
	rm Huffman.o main.o
