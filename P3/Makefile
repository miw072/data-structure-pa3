# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: compress uncompress

compress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o

uncompress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o

HCTree.o: BitInputStream.hpp BitOutputStream.hpp HCNode.hpp HCTree.hpp

HCNode.o: HCNode.hpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp



#compress: HCNode.o HCTree.o BitOutputStream.o

#uncompress: HCNode.o HCTree.o BitOutputStream.o

#HCTree.o: HCNode.hpp HCTree.hpp BitOutputStream.hpp

#HCNode.o: HCNode.hpp

#BitOutputStream.o: BitOutputStream.hpp

clean:
	rm -f compress uncompress *.o core*

