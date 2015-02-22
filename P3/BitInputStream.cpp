/**
* BitOutputStream.cpp for PA3
* Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/20
* The class is for FINAL SUBMISSION, output bit by bit
*/

#include "BitInputStream.hpp"

using namespace std;

void BitInputStream::fill(){
	buffer = in.get();
	nbits = 0;
}
char BitInputStream::getBit(){
	if(nbits == 8){
	    fill();
	}
	
	nbits++;
  
  //printf("%d", (int)((buffer >> (8 - nbits)) & 1));
	return ((buffer >> (8 - nbits)) & 1);
}
