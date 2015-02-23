/**
 * compress.cpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/11
 * This cpp file is used to compress an infile to an outfile using Huffman Coding
 */
 
 
#include "HCTree.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

/* writeInt
 * This method is to write a int to the output file
 * Input: out is the output stream, num is the int to be written
 */
void writeInt(ofstream &out, int num){
  unsigned char c;
  c = (num >> 24);
  out.put(c);
  c = (num >> 16);
  out.put(c);
  c = (num >> 8);
  out.put(c);
  c = (num);
  out.put(c);
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
	
	//create a int vector of frequency of each symbol
	vector<int> freqs(256, 0);
  
	//calculate frequency of each symbol
	if (ifs.is_open()){
		unsigned char ch;
		
		while (1){
			ch = ifs.get();
      
            //if reach to the eof, break
            if (!ifs.good()){
                break;
            }
			freqs[ch] ++;
	    }
		
		if (!ifs.eof()){
			printf("error: cannot read the end of file!\n");
		    return -1;
        }
	}else{
		printf("error: cannot open file\n");
	}
	
  //calculate the total value of symbol, used for loop-controling in uncompress
  unsigned int total = 0;
  for (int i = 0; i < freqs.size(); i++){
    total += freqs[i];
  }
  
	//build the Huffman Code Tree
	HCTree hcTree;
	hcTree.build(freqs);
	
  //clear the error state and move back to the begin of the file
  ifs.clear();
  ifs.seekg(0);
 
  //declare output file stream and open the outfile
	std::ofstream ofs;
	ofs.open(outfile, std::ofstream::out | std::ofstream::app | std::ofstream::binary);
  
  //write total and the number of bits of header to outfile
	writeInt(ofs, total);
  writeInt(ofs, hcTree.getCount());
 
  BitOutputStream out(ofs);
  
  //write header to outfile
  hcTree.writeHeader(out);
  
  //encode the infile
  if (ifs.is_open()){
     unsigned char ch = ifs.get();	
	   while (ifs.good()){
         hcTree.encode(ch, out);
         ch = ifs.get();
	   }
     //need to flush everything left in the buffer
	   out.flush();
   
	   if (!ifs.eof()){
	       printf("error: cannot read the end of file!\n");
		     return -1;
     }
  }else{
	    printf("error: cannot open file\n");
  }
  
  //close infile and outfile
  ifs.close();
  ofs.close();
	
}
