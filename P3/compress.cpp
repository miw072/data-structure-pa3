/**
 * compress.cpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingyu Wang(TO DO) 2015/2/11
 * This cpp file is used to compress an infile to an outfile using Huffman Coding
 */
 
#include "HCTree.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

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

void writeHeader(ofstream &out, vector<int> &freqs, int count){
  for (int i = 0; i < freqs.size(); i++){
    writeInt(out, count);
    
    if (freqs[i]){
      unsigned char c = i;
      out.put(c);
      
      int num = freqs[i];
      writeInt(out, num);
    }
  }
}



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
	//count is used for header
  int count = 0;
  
	//calculate frequency of each symbol
	if (ifs.is_open()){
		unsigned char ch;
		
		while (ifs.good()){
			ch = ifs.get();
			freqs[ch] ++;
		}
		
		if (!ifs.eof()){
			printf("error: cannot read the end of file!\n");
		  return -1;
    }
	}else{
		printf("error: cannot open file\n");
	}
	
	//build the Huffman Code Tree
	HCTree hcTree;
	hcTree.build(freqs);
	
  ifs.clear();
  ifs.seekg(0);
 
  //declare output file stream and open the outfile
	std::ofstream ofs;
	ofs.open(outfile, std::ofstream::out | std::ofstream::app);
	
  //write header
  writeHeader(ofs, freqs, hcTree.getCount());  
  
  //encode the infile
  if (ifs.is_open()){
		unsigned char ch;
		
		while (ifs.good()){
			ch = ifs.get();
      hcTree.encode(ch, ofs);
		}
		
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