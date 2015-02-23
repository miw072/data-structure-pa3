/**
 * BitOutputStream.cpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/20
 * The class is for FINAL SUBMISSION, output bit by bit
 */

#include "BitInputStream.hpp"

using namespace std;

/* BitInputStream::fill()
 * This method is to fill in the buffer when necessary 
 */

void BitInputStream::fill(){
	buffer = in.get();
	nbits = 0;
}

/* BitInputStream::getBit()
 * This method is to read a bit from the buffer
 * Output: a bit of 0 or 1 present as char 
 */

char BitInputStream::getBit(){
	//buffer is empty, need to fill in
  if(nbits == 8){
	    fill();
	}
	
	nbits++;
  
	return ((buffer >> (8 - nbits)) & 1);
}
