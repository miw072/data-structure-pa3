/**
 * compress.cpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/11
 * This cpp file is used to uncompress an infile to an outfile using Huffman Coding
 */
 
 
#include "HCTree.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <queue>

/* readInt
 * This method is to read a int from the input file
 * Input: in is the input stream
 */
unsigned int readInt(ifstream &in){
  unsigned int num = (in.get()<<24) | (in.get()<<16) | (in.get()<<8) | (in.get());
  return num;
}

/* main
 * This method is the main method of command line program 
 */
int main(int argc, char* argv[]){
  
  if (argc != 3){
    printf("Invalid command line input. Please follow the instructions and restart!\n");
    return -1;
  }
  
  string infile = argv[1];
  string outfile = argv[2];
	   
  //declare iuput file stream and open the infile
  std::ifstream ifs;
  ifs.open (infile, std::ifstream::in | std::ifstream::binary);
	
  //read total number of symbols and count for header in
  unsigned int total = readInt(ifs);
  int headerCount = readInt(ifs);
  
  HCTree hcTree;
  
  //declare output file stream and open the outfile
  std::ofstream ofs;
  ofs.open(outfile, std::ofstream::out | std::ofstream::app);
  BitInputStream input(ifs);
  
  //create a queue, push header as int to it
  std::queue<int> headerQueue;
  for (int i = 0; i < headerCount; i++){
      int bit = input.getBit();
      headerQueue.push(bit);
  }
  
  //if there is only one node in the tree
  bool isSingle = headerQueue.front() == 1;
  
  //rebuild the tree according to the header
  hcTree.rebuild(headerQueue, isSingle);
  
  //calculate the left bits in the last buffer, use this to move the pointer of the file to right place
  int left = 8 - (headerCount % 8);
  
  if (ifs.is_open()){
		 
    for (int i = 0; i < left; i++){
        int tmp = input.getBit();
    }
    
    //decode
    for (int i = 0; i < total; i++){
      ofs.put((unsigned char)hcTree.decode(input));
    }
		
	}else{
		printf("error: cannot open file\n");
	}
  
  ifs.close();
  ofs.close();
}
